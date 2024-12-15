#include "BPlusTree.hpp"

BPlusTree::BPlusTree(int _order){
    this->order = _order;
    this->root = nullptr;
}

BPlusTree::~BPlusTree() {
    delete root;
}
void BPlusTree::Insert(int key, vector<string> value){
    if(!this->root){
        this->root = new Node(order, true);
        this->root->keys.push_back(key);
        this->root->values.push_back(value);
        return;
    }

    Node* root_node = this->root;
    if(root_node->keys.size() == order - 1){ // maximum number of keys is "order - 1"
        // root is full, create new node
        Node* new_node = new Node(order, false); // new node is internal node(or nonleaf node)
        new_node->child_node.push_back(root_node); // Link the old root
        this->root = new_node;
        new_node->SplitChild(0);
        new_node->InsertNoFull(key, value);
    }else{
        root_node->InsertNoFull(key, value);
    }
}

void BPlusTree::PrintTree(){
    root->Print();
}

void BPlusTree::Search(int key) const{
    if(!root){
        cout << "not BPlusTree" << endl;
    }else{
        root->SearchNode(key);
    } 
}

void BPlusTree::Delete(int key){
    if(!root){
        cout << "not BPlusTree" << endl;
    }else{
        root->DeleteNode(key);
    }
}