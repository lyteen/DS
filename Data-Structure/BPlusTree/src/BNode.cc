#include "BPlusTree.hpp"

// TODO:
// how use smartpointer
// This destroy function and recusion function may make death loop
inline void DestroyRoutine(Node* node){
    if(node->next_node){
        node->next_node = nullptr;
    }
    for(int i = 0; i < node->child_node.size(); i++){
        node->child_node[i] = nullptr;
    }
    delete node;
}

Node::Node(int _order, bool _isleaf){
    this->order = _order;
    this->isleaf = _isleaf;
    this->next_node = nullptr; 
}

Node::~Node() {
    if (!isleaf) {
        for (auto* child : child_node) {
            delete child; // this will recursively call child node destructors if necessary.
        }
    }
    delete next_node; 
}

void Node::InsertNoFull(int key, vector<string> value){
    size_t pos = lower_bound(keys.begin(), keys.end(), key) - keys.begin();
    if(isleaf){
        // Insert the key and value at the calculated position
        keys.insert(keys.begin() + pos, key);
        values.insert(values.begin() + pos, value); // move the same relative keys position
    }else{// if is non leaf node
        if(child_node[pos]->keys.size() == order - 1){ // if key[i] relative child_node is full, split the child_node
            this->SplitChild(pos);
            if(keys[pos] < key){
                pos += 1; // find the keys[i] > key
            }
        }
        child_node[pos]->InsertNoFull(key, value); // recursion child node insert the key and value
    }
}

// from parent node, spilt child node, create the same level child node
void Node::SplitChild(int pos){
    Node* full_node = this->child_node[pos];
    Node* new_node = new Node(order, full_node->isleaf);

    // split keys
    /*
        add "7":
        first split "4":
                                parent: ["2", "4"]
        splits: ["0", "1"], ["2", "3"], new_node: ["4", "5", "6"]
        second add:
                                parent: ["2", "4"]
        splits: ["0", "1"], ["2", "3"], new_node: ["4", "5", "6", "7"]
        add: ["8", "9", "10"]
                                parent: ["2", "4", "6"]
        splits: ["0", "1"], ["2", "3"], ["4", "5"], new_node: ["6", "7", "8", "9", "10"]
        add: ["11", "12", "13", "14"]
                                            parent: ["6"]
                                son: ["2", "4"],  new_node: ["6", "8", "10", "12"]
        splits: l_node: ["0", "1"], ["2", "3"]    r_node: ["4", "5"], ["6", "7"], ["8", "9"], ["10", "11"], new_node: ["12", "13", "14"]
        add: ["15", "16", "17", "18", "19"]
                                            parent: ["6", "10"]
                                son: ["2", "4"], ["6", "8"] new_node: ["10", "12", "14", "16"]
        splits: l_node: ["0", "1"], ["2", "3"]    r_node: ["4", "5"], ["6", "7"], ["8", "9"], ["10", "11"], ["12", "13"], ["14", "15"], new_node: ["16", "17", "18", "19"]
    */

    int mid = this->order / 2;
    this->keys.insert(keys.begin() + pos, full_node->keys[mid]); // copy the keys[pos] to parent node keys
    
    // for leaf, split full_node keys, and copy keys[mid] to parents
    // for nonleaf, only need split full_node keys(pos >= mid + 1), and copy keys[mid] to parents
    if(full_node->isleaf){
        new_node->keys.assign(full_node->keys.begin() + mid, full_node->keys.end());
        new_node->values.assign(full_node->values.begin() + mid, full_node->values.end());
        full_node->keys.resize(mid); // clear the over keys 
        full_node->values.resize(mid);
        full_node->next_node = new_node; // if is leaf node, connected list
    }else{
        // For non-leaf nodes, move the mid key up
        new_node->keys.assign(full_node->keys.begin() + mid + 1, full_node->keys.end());
        new_node->child_node.assign(full_node->child_node.begin() + mid + 1, full_node->child_node.end());
        full_node->keys.resize(mid);
        full_node->child_node.resize(mid + 1);
    }

    if(pos == this->child_node.size() - 1){
        this->child_node.push_back(new_node);
    }else{
        this->child_node.insert(child_node.begin() + pos + 1, new_node);
    } // add the new child_node
}

void Node::Print(){
    if(isleaf){
        for(size_t i = 0; i < keys.size(); i++){
            cout << "key " << keys[i] << ": [ ";
            for(auto v: values[i]){
                cout << v << " ";
            }
            cout << "]" << endl;
        }
    }else{
        for(size_t i = 0; i < child_node.size(); i++){
            child_node[i]->Print();
        }
    }
}

void Node::SearchNode(int key) const{
    if(isleaf){
        int pos = keys.size() - 1;
        while(pos >= 0 && keys[pos] != key){
            pos--;
        }
        if(pos >= 0 && keys[pos] == key){
            cout << "search key: " << key << "[ ";
            for(auto v: values[pos]){
                cout << v << " ";
            }
            cout << " ]" << endl;
            return;
        }else{
            cout << "key: " << key << " not in BPlusTree" << endl;
            return;
        }
    }else{
        int pos = keys.size() - 1;
        while(pos >= 0 && keys[pos] > key){
            pos--;
        }
        pos += 1;
        this->child_node[pos]->SearchNode(key);
    }
}

/*
    delectNode:
        main ideas: leaf must keep number keys >= ceil(order / 2) // Minkey
        if(!isleaf && keys.size() <= Minkey){HandleUnderflow}
        HandleUnderflow:
            1.if left node keys.size() > order / 2, BorrowFromLeftSibling, 
            2.if right node keys.size() > order / 2, BorrowFromRightSibling
            3.if !(left_node), MergeWithLeftSibling
            4.if !(right_node), MergeWithRightSibling
*/
void Node::DeleteNode(int key){
    int pos = lower_bound(keys.begin(), keys.end(), key) - keys.begin();
    int minKeys = ceil((order - 1) / 2.0);
    bool status = true;
    if(this->isleaf){
        if(pos < keys.size() && keys[pos] == key){
            keys.erase(keys.begin() + pos);
            values.erase(values.begin() + pos);
        } else {
            cout << "Key " << key << " not found in the tree." << endl;
            return; // Key not found
        }
    }else{
        if (pos < keys.size() && keys[pos] == key) { // key found in internal node
            pos++; // Move to the right child to find the successor
        }
        if(this->child_node[pos]->keys.size() <= minKeys){
            status = this->HandleUnderflow(pos);
        }
        if(!status && pos > 0){
            this->child_node[pos - 1]->DeleteNode(key); // if merge left_child deleted key move pos - 1
        }else{
            this->child_node[pos]->DeleteNode(key);
        }
    }
}

bool Node::HandleUnderflow(int pos){
    int minKeys = ceil((order - 1) / 2.0);
    
    Node* left_node = (pos > 0) ? child_node[pos - 1] : nullptr;
    Node* right_node = (pos < child_node.size() - 1) ? child_node[pos + 1] : nullptr;
    
    if(left_node && left_node->keys.size() > minKeys){
        this->BorrowFromLeftSibling(pos);
        return true;
    }else if(right_node && right_node->keys.size() > minKeys){
        this->BorrowFromRightSibling(pos);
        return true;
    }else{
        if(left_node){
            this->MergeWithLeftSibing(pos);
            return false; // if merge the leftsibing the child_node[pos] cant point correct position
        }else{
            this->MergeWithRightSibing(pos);
            return true;
        }
    }
}

void Node::BorrowFromLeftSibling(int pos){
    Node* left_node = this->child_node[pos - 1];
    Node* current_node = this->child_node[pos];
    
    // if left_node is nonleaf move last child_node to current_node
    // if left_node is leaf move last values to current_node
    if(!left_node->isleaf){
        current_node->keys.insert(current_node->keys.begin(), this->keys[pos - 1]);
        this->keys[pos - 1] = left_node->keys.back(); // copy the left child_node last element to parent
        left_node->keys.pop_back();
        current_node->child_node.insert(current_node->child_node.begin(), left_node->child_node.back());
        left_node->child_node.pop_back();
    }else{
        this->keys[pos - 1] = left_node->keys.back();
        current_node->keys.insert(current_node->keys.begin(), this->keys[pos - 1]);
        current_node->values.insert(current_node->values.begin(), left_node->values.back());
        left_node->keys.pop_back();
        left_node->values.pop_back();
    }
}

void Node::BorrowFromRightSibling(int pos){
    Node* right_node = this->child_node[pos + 1];
    Node* current_node = this->child_node[pos];
    

    // if right_node is nonleaf move first child_node to current_node
    // if right_node is leaf move first values to current_node
    if(!right_node->isleaf){
        current_node->keys.push_back(this->keys[pos]);
        this->keys[pos] = right_node->keys.front();
        right_node->keys.erase(right_node->keys.begin());
        current_node->child_node.push_back(right_node->child_node.front());
        right_node->child_node.erase(right_node->child_node.begin());
    }else{
        current_node->keys.push_back(this->keys[pos]);
        this->keys[pos] = right_node->keys[1]; // copy right child_node second element to parent
        right_node->keys.erase(right_node->keys.begin());
        current_node->values.push_back(right_node->values.front());
        right_node->values.erase(right_node->values.begin());
    }
}
/*
del: "8"
                                            parent: ["6", "10"]
                                son: ["2", "4"], ["6", "8"] new_node: ["10", "12", "14", "16"]
        splits: l_node: ["0", "1"], ["2", "3"], ["4", "5"], ["6", "7"], ["8", "9"], ["10", "11"], ["12", "13"], ["14", "15"], new_node: ["16", "17", "18", "19"]
*/
void Node::MergeWithLeftSibing(int pos){
    Node* left_node = this->child_node[pos - 1];
    Node* current_node = this->child_node[pos];
    
    if(!left_node->isleaf){
        // move key from parent to left sibling
        left_node->keys.push_back(this->keys[pos - 1]);
        // move the current_node all keys to left_node
        left_node->keys.insert(left_node->keys.end(), current_node->keys.begin(), current_node->keys.end());
        left_node->child_node.insert(left_node->child_node.end(), current_node->child_node.begin(), current_node->child_node.end());
    }else{
        // move the current_node all keys to left_node
        left_node->keys.insert(left_node->keys.end(), current_node->keys.begin(), current_node->keys.end());
        left_node->values.insert(left_node->values.end(), current_node->values.begin(), current_node->values.end());
    }
    // erase parent_node keys[pos - 1]
    this->keys.erase(this->keys.begin() + pos - 1);
    // erase parent_node -> current_node
    this->child_node.erase(this->child_node.begin() + pos);
    if (current_node) {
        DestroyRoutine(current_node);  // Only delete if dynamically allocated
    }
}

void Node::MergeWithRightSibing(int pos){
    Node* right_node = this->child_node[pos + 1];
    Node* current_node = this->child_node[pos];
    
    
    if(!right_node->isleaf){
        // move key from parent to current node
        current_node->keys.push_back(keys[pos]);
        // move the right_node all key to current_node
        current_node->keys.insert(current_node->keys.end(), right_node->keys.begin(), right_node->keys.end());
        current_node->child_node.insert(current_node->child_node.end(), right_node->child_node.begin(), right_node->child_node.end());
    }else{
        // move the right_node all key to current_node
        current_node->keys.insert(current_node->keys.end(), right_node->keys.begin(), right_node->keys.end());
        current_node->values.insert(current_node->values.end(), right_node->values.begin(), right_node->values.end());
    }
    // erase parent_node key[pos]
    this->keys.erase(this->keys.begin() + pos);
    // erase parent_node -> right_node
    this->child_node.erase(this->child_node.begin() + pos + 1);
    if (current_node) {
        cout << "enter Destroy" << endl;
        DestroyRoutine(right_node);  // Only delete if dynamically allocated
    }
}