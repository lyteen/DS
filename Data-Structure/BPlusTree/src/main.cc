#include "BPlusTree.hpp"

int main(){
    BPlusTree btree(4); // Small order for easier debugging
    
    btree.Insert(5, {"A", "keys.insert(keys.begin()"});
    btree.Insert(10, {"B"});
    btree.Insert(15, {"C"});
    btree.Insert(20, {"D"});
    btree.Insert(25, {"E"}); // Should trigger a split
    btree.Insert(30, {"F"});
    btree.Insert(35, {"A"});
    btree.Insert(40, {"F"});
    btree.Insert(200, {"F"});
    btree.Insert(50, {"F"});
    btree.Insert(60, {"F"});
    btree.Insert(70, {"F"});
    
    btree.PrintTree();
    btree.Search(15);
    btree.Search(5);
    btree.Search(25);
    btree.Search(35);
    btree.Search(40);
    btree.Search(50);
    btree.Search(70);
    btree.Search(45);

    btree.Delete(70);
    btree.Delete(40);
    btree.Delete(30);
    btree.PrintTree();
    return 0;
}