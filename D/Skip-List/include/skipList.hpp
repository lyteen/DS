#ifndef SKIP_LIST
#define SKIP_LIST
#include <iostream>
#include <vector>
#include <random>

constexpr int MAX_LEVEL = 32;
constexpr double P_FACTOR = 0.25;

using namespace std;
struct SkipListNode
{
    int val;
    vector<SkipListNode *> forward;
    SkipListNode(int _val, int _maxLevel = MAX_LEVEL) : val(_val), forward(_maxLevel, nullptr) {}
};

class SkipList
{
private:
    SkipListNode *head;
    int level;
    mt19937 generator{random_device{}()}; // mt19937 is high quality and efficiency Mersenne Twister engine that generates pseudo-random numbers.
    uniform_real_distribution<double> dis; // get the random number <double>

public:
    SkipList(): head(new SkipListNode(-1)), level(0), dis(0, 1) {} // init the SkipList
    int randomLevel();
    bool search(int target);
    void add(int num);
    void printNode();
    bool erase(int num);
};
#endif //SKIP_LIST