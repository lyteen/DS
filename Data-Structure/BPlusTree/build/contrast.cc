void DelectNode(int key){
    bool status = 0;
    int pos = keys.size() - 1;
    while(pos >= 0 && key < keys[pos]){
        pos -= 1;
    }
    pos += 1;
    if(isleaf && keys[pos] == key){
        keys.erase(keys.begin() + pos);
        values.erase(values.begin() + pos);
        status = true;
    }else{
        // check is minimize node
        if(pos + 1 < child_node.size() && child_node[pos + 1]->keys.size() == order / 2){
            HandleUnderflow(pos + 1);
        }
        child_node[pos + 1]->DelectNode(key); // this 
    }
    if(!status){
        cout << "key: " << key << " not in BPlusTree " << endl;
    }else{
        cout << "key: " << key << " delete successful" << endl;
    }
}

void HandleUnderflow(int pos){
    
    Node* left_node = nullptr;
    Node* right_node = nullptr;
    
    // check the left node isnt minimize
    if(pos - 1 > 0){
        Node* left_node = child_node[pos - 1];
    }
    // check the right node isnt minimize
    if(pos + 1 < child_node[pos]->keys.size()){
        Node* right_node = child_node[pos + 1];
    }
    if(!left_node && child_node[pos - 1]->keys.size() > order / 2){
        BorrowFromLeftSibling(pos);
    }else if(!right_node && child_node[pos + 1]->keys.size() > order / 2){
        BorrowFromRightSibling(pos);
    }else{
        if(!left_node){
            MergeWithRightSibing(pos);
        }else{
            MergeWithLeftSibing(pos);
        }
    }
}