/*
 * binary tree maximum path sum 
 * Song Qiang <qiang.song@usc.edu> 2012
 */


/*

Binary Tree Maximum Path Sum
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

» Solve this problem

 */


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
    int 
    maxPathSum(TreeNode *root) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int max = std::numeric_limits<int>::min();
        max_root_leaf(root, max);
        return max;
    }

    int
    max_root_leaf(TreeNode *root, int &max)
    {
        if (root == NULL) return 0;

        int l = max_root_leaf(root->left, max);
        int r = max_root_leaf(root->right, max);

        int best = root->val + std::max(std::max(l, r), std::max(0, l + r));
        max = std::max(max, best);
        
        return root->val + std::max(std::max(l, r), 0);
    }
};
