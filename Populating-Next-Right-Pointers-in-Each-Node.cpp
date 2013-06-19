/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there
is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.

You may assume that it is a perfect binary tree (ie, all leaves are at
the same level, and every parent has two children).

For example,
Given the following perfect binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

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
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (root == NULL) return;

        root->next = NULL;

        TreeLinkNode* head = root;
        TreeLinkNode* h = head->left;
        while (h != NULL)
        {
            TreeLinkNode* q = h;
            TreeLinkNode* p = head;
            q->next = p->right;
            q = q->next;
            p = p->next;
            while (p != NULL)
            {
                q->next = p->left;
                q = q->next;
                q->next = p->right;
                q = q->next;
                p = p->next;
            }
            q->next = NULL;

            head = h;
            h = head->left;
        }

    }


};




int
main(int argn, char** argv)
{
    Solution s;
}

