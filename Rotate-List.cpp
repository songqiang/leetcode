/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

Given a list, rotate the list to the right by k places, where k is
non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        // count number of nodes
        size_t n = 0;
        ListNode* p = head;
        while (p != NULL)
        {
            ++n;
            p = p->next;
        }

        if (n == 0 || k % n == 0) return head;

        int step = n - k % n;

        ListNode* new_head = head;
        for (int i = 0; i < step - 1; ++i)
        {
            new_head = new_head->next;
        }
        
        p = new_head->next;
        new_head->next = NULL;
        new_head = p;
        
        new_head;
        while (p->next != NULL) p = p->next;
        p->next = head;

        return new_head;


    }
};



