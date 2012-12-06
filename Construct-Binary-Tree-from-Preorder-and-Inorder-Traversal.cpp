/*
 * Song Qiang <qiang.song@usc.edu> 2012
 */


/*

Construct Binary Tree from Preorder and Inorder Traversal
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        return buildTree(preorder.begin(), preorder.end(),
                         inorder.begin(), inorder.end());
    }

    TreeNode*
    buildTree(vector<int>::const_iterator preorder_start,
              vector<int>::const_iterator preorder_end,
              vector<int>::const_iterator inorder_start,
              vector<int>::const_iterator inorder_end)
    {
        if (inorder_start == inorder_end)
            return NULL;

        const int val = *preorder_start;

        TreeNode* root = new TreeNode(val);
        
        const vector<int>::const_iterator root_itr
            = std::find(inorder_start, inorder_end, val); 

        const size_t n_left = root_itr - inorder_start;

        root->left = buildTree(preorder_start + 1, preorder_start + 1 + n_left,
                               inorder_start, inorder_start + n_left);
        
        root->right = buildTree(preorder_start + 1 + n_left, preorder_end,
                                root_itr + 1, inorder_end);

        return root;
    }

};
