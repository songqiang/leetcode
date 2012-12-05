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


/*

Binary Tree Level Order Traversal

Given a binary tree, return the level order traversal of its nodes'
values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

confused what "{1,#,2,3}" means? > read more on how binary tree is
serialized on OJ.

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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > r;
        
        std::queue<TreeNode*> q;
        std::queue<size_t> level;

        q.push(root);
        level.push(0);

        while (!q.empty())
        {
            if (q.front() == NULL)
            {
                q.pop();
                level.pop();
            }
            else
            {
                q.push(q.front()->left);
                level.push(level.front() + 1);

                q.push(q.front()->right);
                level.push(level.front() + 1);
                
                if (r.size() == level.front()) r.push_back(vector<int>());

                r.back().push_back(q.front()->val);
                q.pop();
                level.pop();
            }
        }

        return r;
    }
};

/*

Binary Tree Level Order Traversal II

Given a binary tree, return the bottom-up level order traversal of its
nodes' values. (ie, from left to right, level by level from leaf to
root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7]
  [9,20],
  [3],
]

 */

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > r;
        
        std::queue<TreeNode*> q;
        std::queue<size_t> level;

        q.push(root);
        level.push(0);

        while (!q.empty())
        {
            if (q.front() == NULL)
            {
                q.pop();
                level.pop();
            }
            else
            {
                q.push(q.front()->left);
                level.push(level.front() + 1);

                q.push(q.front()->right);
                level.push(level.front() + 1);
                
                if (r.size() == level.front()) r.push_back(vector<int>());

                r.back().push_back(q.front()->val);
                q.pop();
                level.pop();
            }
        }

        std::reverse(r.begin(), r.end());

        return r;
    }
};



