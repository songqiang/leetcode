/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given a sorted linked list, delete all nodes that have duplicate
numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

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

        ListNode* h = new ListNode(0);
        ListNode* t = h;

        ListNode* p = head;
        while (p != NULL)
        {
            ListNode* q = p->next;
            int n = 1;
            while (q != NULL && q->val == p->val)
            {
                ++n;
                q = q->next;
            }


            if (n == 1)
            {
                t->next = p;
                t = t->next;
                t->next = NULL;
                p  = q;
            }
            else
            {
                while (p != q)
                {
                    ListNode* tmp = p;
                    p = p->next;
                    delete tmp;
                }
            }

        }

        t = h;
        h = h->next;
        delete t;
        return h;
        
    }


};

int
main(int argn, char** argv)
{
    Solution s;
}

