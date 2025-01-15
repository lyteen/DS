#include <iostream>
#include "skipList.hpp"

using namespace std;

int main()
{
    SkipList skiplist; // init the skiplist
    
    // add the num
    skiplist.add(1);
    skiplist.add(2);
    skiplist.add(3);
    skiplist.add(4);
    skiplist.add(5);
    skiplist.add(6);
    skiplist.add(7);
    skiplist.add(10);
    skiplist.add(8);
    skiplist.add(9);

    skiplist.printNode();

    // erase node value
    int erase_num = 8;
    cout << "erase_num:" << erase_num << endl;
    skiplist.erase(erase_num);
    skiplist.printNode();

    // search the value
    int search_num = 7;
    cout << "search_num:" << search_num << endl;
    if(skiplist.search(search_num))
    {
        cout <<  search_num << " in skiplist" << endl;
    }
    
    return 0;
}