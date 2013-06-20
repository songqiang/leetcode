/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary
tree in which the depth of the two subtrees of every node never differ
by more than 1.

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
    int 
    depth(TreeNode* r, bool &good)
    {
        if (r == NULL) return 0;
        
        if (!good) return -1;
        const int ld = depth(r->left, good);
        if (!good) return -1;
        const int rd = depth(r->right, good);
        good &= abs(ld - rd) <= 1;
        return max(ld, rd) + 1;
    }
    
    bool
    isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        bool good = true;
        depth(root, good);
        return good;
    }

};


int
main(int argn, char** argv)
{
    Solution s;
}

