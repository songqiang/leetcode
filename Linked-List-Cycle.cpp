/*
 * Song Qiang <keeyang@ustc.edu>
 */

/*

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space? 

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

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    void
    printList(ListNode* h)
    {
        ListNode* t = h;
        while (t != NULL)
        {
            cout << t->val << "\t";
            t = t->next;
        }
        cout << endl;
    }

    void
    clearList(ListNode* h)
    {
        while (h != NULL)
        {
            ListNode* t = h->next;
            delete h;
            h = t;
        }
    }

    bool hasCycle(ListNode *head) {
        
        if (head == NULL) return false;

        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while (p2 != NULL && p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
            if (p2 != NULL) p2 = p2->next;
        }

        return p2 != NULL;


    }    
};


int
main(int argn, char** argv)
{
    ListNode* h = new ListNode(1);
    h->next = new ListNode(2);
    h->next->next = new ListNode(3);
    h->next->next->next = new ListNode(4);
    h->next->next->next->next = new ListNode(5);

    Solution s;
    s.printList(h);
    s.printList(h);
    s.clearList(h);
}
