/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note: A solution using O(n) space is pretty straight forward. Could
you devise a constant space solution?  

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

    void
    findbadnodes(TreeNode* r, TreeNode* &prev, vector<TreeNode*> &badnodes)
    {
        if (r->left != NULL && badnodes.size() < 4)
            findbadnodes(r->left, prev, badnodes);

        if (prev != NULL && prev->val > r->val)
        {
            badnodes.push_back(prev);
            badnodes.push_back(r);
        }

        prev = r;
        if (r->right != NULL && badnodes.size() < 4)
            findbadnodes(r->right, prev, badnodes);
    }
    
    void
    recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<TreeNode*> badnodes;
        TreeNode* prev = NULL;
        findbadnodes(root, prev, badnodes);
        swap(badnodes.front()->val, badnodes.back()->val);
    }
};

int
main(int argn, char** argv)
{
    Solution s;
}

