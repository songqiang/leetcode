/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

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
#include <set>
#include <queue>


using namespace std;


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function


        if (root == NULL) return vector<vector<int> >();

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        vector<vector<int> > results;
        vector<int> r;
        while (!q.empty())
        {
            const TreeNode* p = q.front();
            q.pop();
            
            if (p == NULL)
            {
                if (!r.empty()) results.push_back(r);
                if (!q.empty()) q.push(NULL);
                r.clear();
            }
            else
            {
                r.push_back(p->val);
                if (p->left != NULL) q.push(p->left);
                if (p->right != NULL) q.push(p->right);
            }
        }
        
        return results;

    }
};


int
main(int argn, char** argv)
{
    Solution s;
}

