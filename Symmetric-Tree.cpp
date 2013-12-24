/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given a binary tree, check whether it is a mirror of itself (ie,
symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:

    1
   / \
  2   2
   \   \
   3    3

Note: Bonus points if you could solve it both recursively and
iteratively.



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

    bool
    isGood(TreeNode* left, TreeNode* right)
    {
        if (left == NULL && right == NULL) return true;
        if (left == NULL && right != NULL
            || left != NULL && right == NULL)
            return false;

        if (left->val != right->val) return false;

        return isGood(left->left, right->right)
            && isGood(left->right, right->left);
    }
    
    bool
    isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        return root == NULL || isGood(root->left, root->right);
    }


    bool
    isSymmetric_non_recursive(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (root == NULL) return true;

        queue<TreeNode*> l;
        queue<TreeNode*> r;
        l.push(root->left);
        r.push(root->right);
        while (!l.empty() && !r.empty())
        {
            if (l.front() == NULL && r.front() == NULL)
                ;
            else if ((l.front() == NULL && r.front() != NULL)
                  || (l.front() != NULL && r.front() == NULL))
                return false;
            else if (l.front()->val != r.front()->val)
                return false;
            else
            {
                l.push(l.front()->left);
                l.push(l.front()->right);
                r.push(r.front()->right);
                r.push(r.front()->left);
            }
            l.pop();
            r.pop();
        }

        return  l.size() == r.size();
    }

};

int
main(int argn, char** argv)
{
    Solution s;
}


// 9,-42,-42,#,76,76,#,#,13,#,13
