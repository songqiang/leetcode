/*
 * Song Qiang <keeyang@ustc.edu>
 */

/*

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [3,2,1]. 


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
#include <stack>
#include <functional>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int>
    postorderTraversal(TreeNode *root) {

        vector<int> r;
        if (root == NULL) return r;

        stack<TreeNode*> nodes;
        stack<bool> visited;
            
        nodes.push(root);
        visited.push(false);
        while (!nodes.empty())
        {
            if (visited.top())
            {
                r.push_back(nodes.top()->val);
                visited.pop();
                nodes.pop();
            }
            else
            {
                visited.top() = true;
                TreeNode* r = nodes.top();

                if (r->right != NULL)
                {
                    nodes.push(r->right);
                    visited.push(false);
                }
                if (r->left != NULL)
                {
                    nodes.push(r->left);
                    visited.push(false);
                }

            }
        }

        return r;
    }
};

int
main(int argn, char** argv)
{
    Solution s;

    TreeNode* t = new TreeNode(3);
    t->left = new TreeNode(1);
    t->right = new TreeNode(2);
    s.postorderTraversal(t);
    delete t->left;
    delete t->right;
    delete t;
}
