#ifndef B_PLUS_TREE
#define B_PLUS_TREE
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Include for lower_bound
#include <cmath>
using namespace std;
class Node{
public:
    int order;
    bool isleaf; // check the node if is a leaf
    vector<int> keys;
    // leaf node
    vector<vector<string>> values; // store each leaf node keys info
    Node* next_node; // pointer the next node
    // internal node
    vector<Node*> child_node; // point the child nodes
public:
    Node(int _order, bool _isleaf);
    ~Node();
    void InsertNoFull(int key, vector<string> value);
    void SplitChild(int pos);
    void Print();
    void SearchNode(int key) const;
    void DeleteNode(int key);
private:
    bool HandleUnderflow(int pos);
    void BorrowFromLeftSibling(int pos);
    void BorrowFromRightSibling(int pos);
    void MergeWithLeftSibing(int pos);
    void MergeWithRightSibing(int pos);
};

class BPlusTree{
public:
    int order;
    Node* root;

    BPlusTree(int _order); // init the bpulsytree
    ~BPlusTree();
    void Insert(int key, vector<string> value); // insert implement
    void PrintTree();
    void Search(int key) const;
    void Delete(int key);
};

#endif