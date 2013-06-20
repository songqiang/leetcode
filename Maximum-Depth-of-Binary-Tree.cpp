/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from
the root node down to the farthest leaf node.

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
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function


        return root == NULL ? 0 : 1 + max(maxDepth(root->left),
                                          maxDepth(root->right));
        

    }
};


int
main(int argn, char** argv)
{
    Solution s;
}

