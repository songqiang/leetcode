/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given a binary tree, return the zigzag level order traversal of its
nodes' values. (ie, from left to right, then right to left for the
next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]

confused what "{1,#,2,3}" means? > read more on how binary tree is
serialized on OJ.

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

    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {

        vector<vector<int> > r;
        if (root ==  NULL) return r;
        
        vector<TreeNode*> q1;
        vector<TreeNode*> q2;
        
        q1.push_back(root);
        while (!q1.empty())
        {
            r.push_back(vector<int>());
            for (size_t i = 0; i < q1.size(); ++i)
            {
                r.back().push_back(q1[i]->val);
                if (q1[i]->left != NULL) q2.push_back(q1[i]->left);
                if (q1[i]->right != NULL) q2.push_back(q1[i]->right);
            }
            q1.assign(q2.begin(), q2.end());
            q2.clear();
        }

        for (size_t i = 1; i < r.size(); i += 2) 
            std::reverse(r[i].begin(), r[i].end());
            
        return r;
    }
};


int
main(int argn, char** argv)
{
    Solution s;
}

