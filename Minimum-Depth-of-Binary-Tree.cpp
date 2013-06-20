/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from
the root node down to the nearest leaf node.

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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (root == NULL) return 0;
        const int ld = minDepth(root->left);
        const int rd = minDepth(root->right);
        if (ld == 0 && rd != 0)
            return 1 + rd;
        else if (ld != 0 && rd == 0)
            return 1 + ld;
        else
            return 1 + min(ld, rd);

    }
};


int
main(int argn, char** argv)
{
    Solution s;
}

