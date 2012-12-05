/*
 * 3sum: http://www.leetcode.com/2010/04/finding-all-unique-triplets-that-sums.html
 * Song Qiang <qiang.song@usc.edu> 2012-10-04
 *
 */

// time complexity: O(n^2)

/*
Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary
tree in which the depth of the two subtrees of every node never differ
by more than 1.  
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

    size_t 
    get_depth(const TreeNode *root)
    {
        if (root == NULL)
            return 0;
        else
        {
            const int ld = get_depth(root->left);
            const int rd = get_depth(root->right);
            if (abs(ld - rd) > 1) 
            {
                is_balanced = false;
            }
            return 1 + std::max(ld, rd);
        }
    }

    bool
    isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        is_balanced = true;
        get_depth(root);
        return is_balanced;
    }

private:
    bool is_balanced;
};

