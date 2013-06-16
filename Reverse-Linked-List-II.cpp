/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Reverse a linked list from position m to n. Do it in-place and in
one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 <= m < n <= length of list.

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

    void
    print(ListNode* &head)
    {
        for (const ListNode* p = head; p != NULL; p = p->next)
            cout << p->val << "\t";
        cout << endl;
    }

    void
    reverse(ListNode* &head, ListNode* &tail)
    {
        if (head == NULL) return;

        ListNode* h = head;
        head = head->next;
        ListNode* t = h;
        t->next = NULL;
        while (head != NULL)
        {
            ListNode* p = head;
            head = head->next;

            p->next = h;
            h = p;
        }

        head = h;
        tail = t;
    }

    ListNode*
    reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (head == NULL) return head;
        if (n == m) return head;

        if (m == 1)
        {
            ListNode* p = head;
            for (int i = 0; i < n - 1; ++i)
                p = p->next;

            ListNode* t = p;
            p =  t->next;
            t->next = NULL;

            reverse(head, t);
            t->next = p;
        }
        else
        {
            ListNode* p = head;
            for (int i = 0; i < m - 2; ++i)
                p = p->next;
            
            ListNode* q = p;
            for (int i = 0; i < n - m + 1; ++i)
                q = q->next;
            
            ListNode* h = p->next;
            ListNode* t = q;
            q = t->next;
            t->next = NULL;

            reverse(h, t);

            p->next = h;
            t->next = q;
        }

        return head;
    }


};

int
main(int argn, char** argv)
{
    Solution s;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    s.print(head);
    head = s.reverseBetween(head, 2, 3);
    s.print(head);
}

