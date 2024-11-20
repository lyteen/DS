#ifndef HFMT_HPP
#define HFMT_HPP
#include <iostream>
#include <vector>
#include <unordered_map>
#define ElemType char

using namespace std;

struct hfmTNode
{
    ElemType element;
    int w;
    hfmTNode *lChild;
    hfmTNode *rChild;

    hfmTNode(ElemType element, int w) : element(element), w(w), lChild(nullptr), rChild(nullptr) {}
};

struct CompareNodes
{
    bool operator()(hfmTNode *a, hfmTNode *b)
    {
        return a->w > b->w;
    }
};

class HfmTree
{
public:
    hfmTNode *CreateHfmTree(const vector<ElemType> &chars, const vector<int> &w);
    void PrintHfmTree(hfmTNode *root);
    void generateCode(hfmTNode *root, unordered_map<ElemType, string> &codes, string str);
    void PrintCodes(unordered_map<ElemType, string> &codes);
    void Decode(hfmTNode *root, string str);
};
#endif //HFMT_HPP