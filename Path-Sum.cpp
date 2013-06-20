/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given a binary tree and a sum, determine if the tree has a
root-to-leaf path such that adding up all the values along the path
equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum
is 22.



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

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:


    void
    hasPathSum(TreeNode* root, int psum, const int target)
    {
        if (root == NULL) throw false;

        if (root->left == NULL && root->right == NULL)
        {
            if (psum + root->val == target) throw true;
        }
        
        if (root->left != NULL)
            hasPathSum(root->left, psum + root->val, target);
        if (root->right != NULL)
            hasPathSum(root->right, psum + root->val, target);
    }

    bool
    hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        try 
        {
            hasPathSum(root, 0, sum);
        }
        catch(bool e)
        {
            return e;
        }
        return false;
        
    }


};


int
main(int argn, char** argv)
{
    Solution s;
}

