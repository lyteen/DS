#include <iostream>
#include <vector>
#include "hfmT.hpp"

using namespace std;

int main()
{
    HfmTree tree;
    vector<char> chars = {'a', 'b', 'c', 'd', 'e'};
    vector<int> frequencies = {10, 5, 15, 8, 3};
    hfmTNode *root = tree.CreateHfmTree(chars, frequencies);
    cout << "HFM-Tree:" << endl;
    tree.PrintHfmTree(root);
    unordered_map<ElemType, string> codes;
    tree.generateCode(root, codes, "");
    tree.PrintCodes(codes);
    cout << "HFM-node code:" << endl;
    string encode = "abcdeedcba";
    cout << "HFM-Encode:" << encode << "->"<< "";
    string hfmCode = tree.CreateCodes(codes, encode);
    cout << hfmCode << endl;
    tree.Decode(root, "100111100010010001101110");
}