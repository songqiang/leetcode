/*
 * Song Qiang <keeyang@ustc.edu>
 */

/*

 Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}. 

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

    void
    reorderList(ListNode *head) {
        
        if (head == NULL) return;

        size_t  n = 0;
        ListNode* t = head;
        while (t != NULL) {
            ++n;
            t = t->next;
        }

        t = head;
        for (size_t i = 0; i < (n - 1) / 2; ++i)
            t = t->next;

        // reversing
        ListNode* h = new ListNode(0);
        while (t->next != NULL)
        {
            ListNode* tmp = t->next;
            t->next = tmp->next;
            
            tmp->next = h->next;
            h->next = tmp;
        }

        t = head;
        while (h->next != NULL)
        {
            ListNode* tmp = h->next;
            h->next = tmp->next;
            
            tmp->next = t->next;
            t->next = tmp;

            t = t->next->next;
        }
        delete h;
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
    s.reorderList(h);
    s.printList(h);
    s.clearList(h);
}
