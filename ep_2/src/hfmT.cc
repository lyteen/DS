#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include "hfmT.hpp"

using namespace std;

hfmTNode* HfmTree::CreateHfmTree(const vector<ElemType> &chars, const vector<int> &w)
{
    priority_queue<hfmTNode*, vector<hfmTNode*>, CompareNodes> pq;

    //Create leaf node and add them to the pq;
    for(int i = 0; i < chars.size(); i++)
    {
        pq.push(new hfmTNode(chars[i], w[i]));
    }

    // Create the internal nodes and add them to the pq;
    while(pq.size() > 1)
    {
        hfmTNode *left = pq.top();
        pq.pop();
        hfmTNode *right = pq.top();
        pq.pop();

        int sum = left->w + right->w;
        hfmTNode *newNode = new hfmTNode('\0', sum);
        newNode->lChild = left;
        newNode->rChild = right;
        pq.push(newNode);
    }

    hfmTNode *root = pq.top();

    return root;
}

void HfmTree::PrintHfmTree(hfmTNode *root)
{
    if(!root)
    {
        return;
    }

    // Check if the node is a leaf node
    if (root->element != '\0')
    {
        cout << "node:" << root->element << ":" << root->w << endl;
    }

    PrintHfmTree(root->lChild);
    PrintHfmTree(root->rChild);
}

void HfmTree::generateCode(hfmTNode *root,  unordered_map<ElemType, string> &codes, string str = "")
{
    if(!root)
    {
        return;
    }

    // Check if the node is a leaf node
    if (root->element != '\0')
    {
        codes[root->element] = str;
    }

    generateCode(root->lChild, codes, str + "0");
    generateCode(root->rChild, codes, str + "1");
}

void HfmTree::PrintCodes(unordered_map<ElemType, string> &codes)
{
    for(auto i = codes.begin(); i != codes.end(); i++)
    {
        cout << "Hfm node:" << i->first << ":" << i->second << endl;
    }

    return;
}

void HfmTree::Decode(hfmTNode *root, string str)
{
    if(!root)
    {
        return;
    }
    cout << "Hfm Decode:" << str << "->";
    hfmTNode *cur = root;
    for(auto i : str)
    {
        if(i == '0')
        {
            cur = cur->lChild;
        } else {
            cur = cur->rChild;
        }

        if(cur->element != '\0')
        {
            cout << cur->element;
            cur = root;
        }
    }
}