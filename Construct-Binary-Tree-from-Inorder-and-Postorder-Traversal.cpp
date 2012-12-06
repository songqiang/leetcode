/*
 * Song Qiang <qiang.song@usc.edu> 2012
 */


/*

Construct Binary Tree from Inorder and Postorder Traversal
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        return buildTree(inorder.begin(), inorder.end(),
                         postorder.begin(), postorder.end());
    }

    TreeNode*
    buildTree(vector<int>::const_iterator inorder_start,
              vector<int>::const_iterator inorder_end,
              vector<int>::const_iterator postorder_start,
              vector<int>::const_iterator postorder_end)
    {
        if (inorder_start == inorder_end)
            return NULL;

        const int val = *(postorder_end - 1);

        TreeNode* root = new TreeNode(val);
        
        const vector<int>::const_iterator root_itr
            = std::find(inorder_start, inorder_end, val); 
        

        root->left = buildTree(inorder_start, root_itr,
                               postorder_start,
                               postorder_start + (root_itr - inorder_start));

        root->right = buildTree(root_itr + 1, inorder_end,
                                postorder_start + (root_itr  - inorder_start),
                                postorder_end - 1);

        return root;
    }

};
