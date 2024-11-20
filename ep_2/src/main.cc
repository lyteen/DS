#include <iostream>
#include <vector>
#include "hfmT.hpp"

using namespace std;

int main()
{
    std::vector<char> chars = {'a', 'b', 'c', 'd', 'e'};
    std::vector<int> frequencies = {10, 5, 15, 8, 3};
    HfmTree tree;
    hfmTNode *root = tree.CreateHfmTree(chars, frequencies);
    tree.PrintHfmTree(root);
    unordered_map<ElemType, string> codes;
    tree.generateCode(root, codes, "");
    tree.PrintCodes(codes);
    tree.Decode(root, "010");
}