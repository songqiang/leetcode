/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given a binary tree and a sum, find all root-to-leaf paths where each
path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
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

    void
    pathsum(TreeNode* root, vector<int> &v, vector<vector<int> >  &results,
            const int psum, const int target)
    {
        if (root == NULL) return;

        v.push_back(root->val);

        if (root->left == NULL && root->right == NULL)
        {
            if (psum + root->val == target)
                results.push_back(v);
        }

        if (root->left != NULL)
            pathsum(root->left, v, results, psum + root->val, target);

        if (root->right != NULL)
            pathsum(root->right, v, results, psum + root->val, target);

        v.pop_back();
        
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<int> v;
        vector<vector<int> > results;
        pathsum(root, v, results, 0, sum);
        return results;

    }
};

int
main(int argn, char** argv)
{
    Solution s;
}

