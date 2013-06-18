/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given n, generate all structurally unique BST's (binary search trees)
that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3


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

    
    vector<TreeNode*> 
    generateTrees(const int begin, const int end)
    {
        vector<TreeNode*> results;
        
        if (begin >= end)
        {
            results.push_back(NULL);
            return results;
        }
        if (begin + 1 == end) return vector<TreeNode*>(1, new TreeNode(begin));


        for (int root = begin; root < end; ++root)
        {
            vector<TreeNode* > leftchilds(generateTrees(begin, root));
            vector<TreeNode* > rightchilds(generateTrees(root + 1, end));
            for (int i = 0; i < leftchilds.size(); ++i)
                for (int j = 0; j < rightchilds.size(); ++j)
                {
                    results.push_back(new TreeNode(root));
                    results.back()->left = leftchilds[i];
                    results.back()->right = rightchilds[j];
                }
        }
        
        return results;
    }

    vector<TreeNode *> 
    generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        return generateTrees(1, n + 1);
    }
};


int
main(int argn, char** argv)
{
    Solution s;
}



