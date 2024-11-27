#include <iostream>
#include <algorithm>
#include "skipList.hpp"

using namespace std;

int SkipList::randomLevel()
{
    int lv = 1;
    // random number if < 0.25 and lv < 25, then make new level
    while(dis(generator) < P_FACTOR && lv < MAX_LEVEL)
    {
        lv++;
    }
    return lv;
}

bool SkipList::search(int target)
{
    SkipListNode *curr = this->head;
    for(int i = level - 1; i >= 0; i--)
    {
        // function find the curr->val > target or == target
        while (curr->forward[i] && curr->forward[i]->val < target)
        {
            curr = curr->forward[i];
        }
    }
    curr = curr->forward[0];
    if(curr && curr->val == target)
    {
        return true;
    }
    return false;
}

void SkipList::add(int num)
{
    // TODO: consider how the vector<*> work
    // -> store the node each level pointer
    vector<SkipListNode *> update(MAX_LEVEL, head);
    SkipListNode *curr = this->head; // point to the header.
    for(int i = level - 1; i >= 0; i--) // traverse top level to bottom to find node that curr->forward[level]->val >= inserted value  
    {
        while(curr->forward[i] && curr->forward[i]->val < num)
        {
            curr = curr->forward[i];
        }
        update[i] = curr;
    }
    int lv = randomLevel();
    level = max(level, lv);
    SkipListNode *newNode = new SkipListNode(num, lv);
    for(int i = 0; i < lv; i++)
    {
        newNode->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = newNode;
    }
}

bool SkipList::erase(int num)
{
    vector<SkipListNode *> update(MAX_LEVEL, nullptr);
    SkipListNode *curr = this->head;
    for(int i = level - 1; i >= 0; i--)
    {
        while(curr->forward[i] && curr->forward[i]->val < num)
        {
            curr = curr->forward[i];
        }
        update[i] = curr;
    }
    curr = curr->forward[0]; // from the bottom level.
    if(!curr || curr->val != num) // examine the node is erased node
    {
        return false;
    }
    for(int i = 0; i < level; i++) // update previous node each level point(before erase point the erased node).
    {
        if(update[i]->forward[i] != curr)
        {
            break;
        }
        update[i]->forward[i] = curr->forward[i];
    }
    delete curr;
    while(level > 1 && head->forward[level - 1] == nullptr) // if erase the head node top level point, downgrade.
    {
        level--;
    }
    return true;
}

void SkipList::printNode()
{
    vector<SkipListNode *> update(MAX_LEVEL, head);
    SkipListNode *curr = this->head;
    cout << "SkipList:" << endl;
    for(int i = 0; i < level; i++)
    {
        cout << "level:" << i << endl;
        while(curr)
        {
            cout << "->" << curr->val;
            curr = curr->forward[i];
        }
        cout << "\n";
        curr = this->head;
    }
}