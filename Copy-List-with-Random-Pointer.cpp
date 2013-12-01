/*
 * Song Qiang <keeyang@ustc.edu>
 */

/*

A linked list is given such that each node contains an additional
random pointer which could point to any node in the list or null.

Return a deep copy of the list. 

 */


#include <cmath>
#include <cassert>

#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <limits>
#include <utility>
#include <set>
#include <queue>
#include <stack>
#include <functional>
#include <unordered_map>


using namespace std;


struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {

        if (head == NULL) return NULL;

        unordered_map<RandomListNode*, RandomListNode*> m;

        RandomListNode* h = new RandomListNode(head->label);
        RandomListNode* t = h;
        RandomListNode* tail = head;
        m[tail] = t;

        tail = tail->next;
        while (tail != NULL)
        {
            t->next = new RandomListNode(tail->label);
            t = t->next;
            m[tail] = t;
            tail = tail->next;
        }

        tail = head;
        t = h;
        while (tail != NULL)
        {
            t->random = m[tail->random];
            t = t->next;
            tail = tail->next;
        }

        return h;
    }
};



int
main(int argn, char** argv)
{
    Solution s;
}



