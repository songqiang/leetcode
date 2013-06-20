/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given a binary tree, return the bottom-up level order traversal of its
nodes' values. (ie, from left to right, level by level from leaf to
root).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:

[ [15,7] [9,20], [3], ] 

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
        
        reverse(results.begin(), results.end());
        return results;

    }
};


int
main(int argn, char** argv)
{
    Solution s;
}

