/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given a linked list, remove the nth node from the end of list and
return its head.

For example,

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes
1->2->3->5.  Note:

Given n will always be valid.
Try to do this in one pass.

 */

#include <cmath>

#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <limits>
#include <utility>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    // one passess
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (head == NULL) return head;

        ListNode* pfast = head;
        ListNode* pslow = head;
        
        // fast forward pfast n times
        for (size_t i = 0; i < n; ++i)
            pfast = pfast->next;

        if (pfast == NULL)
        {
            ListNode* p = head;
            head = head->next;
            delete p;
            return head;
        }

        while (pfast->next != NULL)
        {
            pfast = pfast->next;
            pslow = pslow->next;
        }

        ListNode* p = pslow->next;
        pslow->next = p->next;
        delete p;

        return head;
    }


    // two passess
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (head == NULL) return head;

        ListNode* p = head;
        int N = 0;
        while (p != NULL) 
        {
            ++N;
            p = p->next;
        }

        if (N == n)
        {
            p = head;
            head = head->next;
            delete p;
            return head;
        }

        p = head;
        for (size_t i = 0; i < N - n - 1; ++i)
            p = p->next;

        ListNode *tp = p->next;
        p->next = tp->next;
        delete tp;

        return head;
    }
};


int
main(int argn, char** argv)
{
    Solution s;
    
}

