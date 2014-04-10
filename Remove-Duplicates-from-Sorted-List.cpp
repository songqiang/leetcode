/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given a sorted linked list, delete all duplicates such that each
element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (head == NULL) return head;

        ListNode* h = head;
        ListNode* t = h;

        ListNode* p = h->next;
        t->next = NULL;
        while (p != NULL)
        {
            if (p->val == t->val)
            {
                ListNode* q = p;
                p = p->next;
                delete q;
            }
            else
            {
                ListNode* q = p;
                p = p->next;
                q->next = NULL;
                t->next = q;
                t = t->next;
            }
        }

        return h;


    }
};

class Solution2 {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (head == NULL) return NULL;
        
        ListNode* p = head;
        while (p->next != NULL) 
            if (p->next->val != p->val) 
                p = p->next;
            else {
                ListNode* t = p->next;
                p->next = t->next;
                delete t;
            }

        return head;        
        
    }
};

int
main(int argn, char** argv)
{
    Solution s;
}

