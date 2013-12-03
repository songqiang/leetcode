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

        assert(l1 != NULL && l2 != NULL);
        
        ListNode* h = new ListNode((l1->val + l2->val) % 10);
        int inc = (l1->val + l2->val) / 10;
        
        ListNode* t = h;
        ListNode* t1 = l1->next;
        ListNode* t2 = l2->next;
        
        while (t1 != NULL && t2 != NULL)
        {
            int q = (t1->val + t2->val + inc) % 10;
            inc = (t1->val + t2->val + inc) / 10;
            
            t->next = new ListNode(q);
            t = t->next;
            
            t1 = t1->next;
            t2 = t2->next;
        }

        while (t1 != NULL)
        {
            int q = (t1->val + inc) % 10;
            inc = (t1->val + inc) / 10;
            
            t->next = new ListNode(q);
            t = t->next;
            
            t1 = t1->next;
        }

        while (t2 != NULL)
        {
            int q = (t2->val + inc) % 10;
            inc = (t2->val + inc) / 10;
            
            t->next = new ListNode(q);
            t = t->next;
            
            t2 = t2->next;
        }

        if (inc) t->next = new ListNode(inc);

        return h;

    }
};
