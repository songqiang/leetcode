/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given a linked list and a value x, partition it such that all nodes
less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each
of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
    ListNode* h1 = new ListNode(0);
    ListNode* t1 = h1;
    
    ListNode* h2 = new ListNode(0);
    ListNode* t2 = h2;
    
    while (head != NULL)
    if (head->val < x)
    {
        t1->next = head;
        head = head->next;
        t1 = t1->next;
        t1->next = NULL;
    }
    else   
    {
        t2->next = head;
        head = head->next;
        t2 = t2->next;
        t2->next = NULL;
    }

    head = h1->next;
    if (head == NULL) 
        head = h2->next;
    else
        t1->next = h2->next;

    delete h1;
    delete h2;
    
    return head;    
    }
};

int
main(int argn, char** argv)
{
    Solution s;
}

