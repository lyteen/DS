#include <iostream>
#include "skipList.hpp"

using namespace std;

int main()
{
    SkipList skiplist;
    skiplist.add(7);
    skiplist.add(1);
    skiplist.add(2);
    skiplist.add(10);
    skiplist.add(9);
    skiplist.printNode();
}