/*
 * binary tree traversal 
 * Song Qiang <qiang.song@usc.edu> 2012
 */


/*

Binary Tree Inorder Traversal Given a binary tree, return the inorder
traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?


OJ's Binary Tree Serialization: The serialization of a binary tree
follows a level order traversal, where '#' signifies a path terminator
where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5

The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".  » Solve
this problem

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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        // non-recursive version
        vector<int> r;
        std::stack<TreeNode*> st;
        std::stack<bool> left_checked;
 
        st.push(root);
        left_checked.push(false);

        while (!st.empty())
        {
            if (st.top() == NULL)
            {
                st.pop();
                left_checked.pop();
            }
            else if (left_checked.top())
            {
                r.push_back(st.top()->val);
                TreeNode* right(st.top()->right);
                
                st.pop();
                left_checked.pop();

                st.push(right);
                left_checked.push(false);
            }
            else 
            {
                left_checked.top() = true;

                st.push(st.top()->left);
                left_checked.push(false);
            }
        }

        return r;
    }
};


