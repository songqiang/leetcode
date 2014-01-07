/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given a linked list, swap every two adjacent nodes and return its
head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the
values in the list, only nodes itself can be changed.


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
    
    ListNode *swapPairs(ListNode *head) {
        
        ListNode* tmp = new ListNode(0);
        tmp->next = head;
        ListNode* p = tmp;
        while (p != NULL && p->next != NULL && p->next->next != NULL)
        {
            ListNode* t = p->next;
            p->next = t->next;
            t->next = p->next->next;
            p->next->next = t;
            p = p->next->next;
        } 
        
        head = tmp->next;
        delete tmp;
        return head;
    }

    ListNode *swapPairs_old(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (head == NULL || head->next == NULL) return head;

        // work on head
        ListNode* p = head;
        head = head->next;
        p->next = head->next;
        head->next = p;
        
        // work on others
        p = head->next;
        ListNode* q = p->next;  // how about p == NULL?
        while (q != NULL && q->next != NULL)
        {
            p->next = q->next;
            q->next = p->next->next;
            p->next->next = q;
            p = p->next->next;
            q = p->next;
        }

        return head;
    }
};


int
main(int argn, char** argv)
{
    Solution s;
}

