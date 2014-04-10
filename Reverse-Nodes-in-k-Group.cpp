/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given a linked list, reverse the nodes of a linked list k at a time
and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in
the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be
changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5


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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}; 

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (head == NULL || k <= 1) return head;

        vector<ListNode*> ptrs(k);  // not constant memory
        ListNode* h = new ListNode(0);
        h->next = head;
        ListNode* t = h;
        while (true)
        {
            ListNode* p = t->next;
            int i = 0;
            for (; i < k && p != NULL; ++i, p = p->next)
                ptrs[i] = p;

            if (i < k) break;
            
            ptrs.front()->next = ptrs.back()->next;
            
            for (int i = 0; i < k; ++i)
            {
                t->next = ptrs[k - i - 1];
                t = t->next;
            }
        }

        head = h->next;
        delete h;
        return head;
    }

};


class Solution2 {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {

        if (head == NULL || k <= 1) return head;
        
        ListNode* r = new ListNode(0);
        ListNode* h = r;

        while (true) {
            ListNode* next_head = head;
            int i = 0;
            while (i < k && next_head != NULL) {next_head = next_head->next; ++i;}
            
            if (i < k) {
                h->next = head;
                break;
            } else {
                h->next = head;
                head = head->next;
                ListNode* next_h = h->next;
                for (int j = 0; j < k - 1; ++j) {
                    ListNode* tmp = head->next;
                    head->next = h->next;
                    h->next = head;
                    head = tmp;
                }
                h = next_h;
                head = next_head;
            }
        }
        
        h = r;
        r = r->next;
        delete h;
        return r;
        
        
        
    }
};



int
main(int argn, char** argv)
{
    Solution s;
}

