/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given a binary tree, determine if it is a valid binary search tree
(BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the
node's key.  The right subtree of a node contains only nodes with keys
greater than the node's key.  

Both the left and right subtrees must also be binary search trees.
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

    bool
    isValidBST(TreeNode* root, int &largest, int &smallest)
    {
        if (root == NULL) return true;
        int leftmax = numeric_limits<int>::min();
        int leftmin = numeric_limits<int>::max();
        if (!isValidBST(root->left, leftmax, leftmin))
            return false;

        int rightmax = numeric_limits<int>::min();
        int rightmin = numeric_limits<int>::max();
        if (!isValidBST(root->right, rightmax, rightmin))
            return false;

        largest = max(root->val, rightmax);
        smallest = min(root->val, leftmin);

        return root->val > leftmax && root->val < rightmin;
    }
    
    
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int t;
        return isValidBST(root, t, t);
    }

};



int
main(int argn, char** argv)
{
    Solution s;
}

