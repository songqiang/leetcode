/*
 * Add Two Numbers 
 * 
 * You are given two linked lists representing two non-negative
 * numbers. The digits are stored in reverse order and each of their
 * nodes contain a single digit. Add the two numbers and return it as
 * a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
 * Song Qiang <qiang.song@usc.edu> 2012-10-10
 * 
 * passed
 *
 */

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        ListNode *r = NULL;
        ListNode *t = r;
        
        ListNode *p1 = l1, *p2 = l2;
        
        size_t inc = 0;
        while (p1 != NULL && p2 != NULL)
        {
            const int s = p1->val + p2->val + inc;
            ListNode *p = new ListNode(s % 10);
            if (r == NULL)
            {
                r = p;
                t = p;
            }
            else
            {
                t->next = p;
                t = t->next;
            }
            inc = s / 10;

            p1 = p1->next;
            p2 = p2->next;
        }

        while (p1 != NULL)
        {
            const int s = p1->val + inc;
            ListNode *p = new ListNode(s % 10);
            if (r == NULL)
            {
                r = p;
                t = p;
            }
            else
            {
                t->next = p;
                t = t->next;
            }
            inc = s / 10;

            p1 = p1->next;
        }

        while (p2 != NULL)
        {
            const int s = p2->val + inc;
            ListNode *p = new ListNode(s % 10);
            if (r == NULL)
            {
                r = p;
                t = p;
            }
            else
            {
                t->next = p;
                t = t->next;
            }
            inc = s / 10;

            p2 = p2->next;
        }

        if (inc > 0) t->next = new ListNode(inc);

        return r;
    }
};
