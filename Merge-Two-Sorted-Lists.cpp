/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Merge two sorted linked lists and return it as a new list. The new
list should be made by splicing together the nodes of the first two
lists.

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

    
    ListNode* head = new ListNode(0);
    ListNode* tail = head;
    while (l1 != NULL && l2 != NULL)
        if (l1->val <= l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
            tail->next = NULL;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
            tail = tail->next;
            tail->next = NULL;            
        }

    if (l1 != NULL) tail->next = l1;
    if (l2 != NULL) tail->next = l2;

    tail = head;
    head = head->next;
    delete tail;

    return head;


    }
};


int
main(int argn, char** argv)
{
    Solution s;
}

