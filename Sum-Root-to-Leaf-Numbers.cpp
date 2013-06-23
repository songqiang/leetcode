/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given a binary tree containing digits from 0-9 only, each root-to-leaf
path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the
number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

 */

#include <cmath>

#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>
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
    accu(TreeNode* r, int n, int &sum)
    {
        n *= 10;
        n += r->val;

        if (r->left == NULL && r->right == NULL)
        {
            sum += n;
            return;
        }
        
        if (r->left != NULL)
            accu(r->left, n, sum);
        
        if (r->right != NULL)
            accu(r->right, n, sum);
    }

    int
    sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (root == NULL) return 0; 
        
        int n = 0, sum = 0;
        accu(root, n, sum);
        return sum;
    }
};


int
main(int argn, char** argv)
{
    Solution s;
}

