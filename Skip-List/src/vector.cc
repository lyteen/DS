#include <iostream>
#include <vector>

constexpr int MAX_LEVEL = 10;
using namespace std;
struct SkipListNode
{
    int val;
    vector<SkipListNode *> forward;
    SkipListNode(int _val, int _maxLevel = MAX_LEVEL) : val(_val), forward(_maxLevel, nullptr) {}
};
