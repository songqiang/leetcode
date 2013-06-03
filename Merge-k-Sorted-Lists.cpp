/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Merge k sorted linked lists and return it as one sorted list. Analyze
and describe its complexity.

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
#include <queue>

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
    
    struct Cmp : public binary_function<ListNode*, ListNode*, bool>
    {
        const bool 
        operator()(const ListNode* lhs, const ListNode* rhs) const
        { return lhs != NULL && rhs != NULL && lhs->val > rhs->val;}
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function


        priority_queue<ListNode*, vector<ListNode*>, Cmp> pp;

        for (size_t i = 0; i < lists.size(); ++i)
            if (lists[i] != NULL) pp.push(lists[i]);
        
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        while (!pp.empty())
        {
            ListNode* h = pp.top();
            pp.pop();
            tail->next = h;
            h = h->next;
            tail = tail->next;
            tail->next = NULL;
            if (h != NULL) pp.push(h);
        }

        // fix head
        ListNode* p = head;
        head = head->next;
        delete p;
        return head;
    }
};


int
main(int argn, char** argv)
{
    Solution s;
}

