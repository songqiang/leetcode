/*
 * Song Qiang <qiang.song@usc.edu> 2012
 */


/*

Convert Sorted Array to Binary Search Tree

Given an array where elements are sorted in ascending order, convert
it to a height balanced BST.
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


// sorted array
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        return toBST(num.begin(), num.end());
    }


    TreeNode*
    toBST(const std::vector<int>::const_iterator start,
          const std::vector<int>::const_iterator end)
    {
        if (start == end)
        {
            return NULL;
        }

        const size_t n = distance(start, end);
        const size_t mid = n / 2;

        TreeNode* r = new TreeNode(*(start + mid));
        r->left = toBST(start, start + mid);
        r->right = toBST(start + mid + 1, end);

        return r;
    }
};

// AVL self-balance tree
class Solution {
public:

    struct AugTreeNode {
        int val;
        int height;
        AugTreeNode *left;
        AugTreeNode *right;
        AugTreeNode *parent;
        bool is_left_child;
        AugTreeNode(int x) : val(x), left(NULL), right(NULL),
                             parent(NULL), is_left_child)(true) {}
    };

    TreeNode*
    sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        AugTreeNode* ar;
        for (size_t i = 0; i < num.size(); ++i)
            InsertToBST(ar, num[i]);

        TreeNode* r;
        TrimTree(ar, r);
    }

    void 
    TrimTree(AugTreeNode* &a, TreeNode* &r)
    {
        if (a == NULL)
        {
            r == NULL;
            return;
        }

        r = new TreeNode(a->val);
        TrimTree(a->left, r->left);
        TrimTree(a->rihgt, r->right);
    }

    int
    get_height(const AugTreeNode *r)
    {
        return r == NULL ? 0 : r->height;
    }

    void
    InsertToBST(AugTreeNode *r, const int v)
    {
        if (r == NULL)
        {
            r = new AugTreeNode(v);
            r->parent = NULL;
            r->is_left_child = true;
            r->height = 1;
            return;
        }
        
        if (v < r->val) 
        {
            if (r->left == NULL)
            {
                r->left == new AugTreeNode(v);
                r->left->parent = r;
                r->left->is_left_child = true;
                r->left->height = 1;
            }
            else
            {
                InsertToBST(r->left, v);
            }
        }
        else
        {
            if (r->right == NULL)
            {
                r->right == new AugTreeNode(v);
                r->right->parent = r;
                r->right->is_left_child = false;
                r->right->height = 1;
            }
            else
            {
                InsertToBST(r->right, v);
            }
        }

        r->height = std::max(get_height(r->left), get_height(r->right)) + 1;
        if (get_height(r->left) - get_height(r->right) > 1
            || get_height(r->left) - get_height(r->right) < -1) 
            balanceBST(r);
    }

    void
    balanceBST(AugTreeNode *r)
    {
        // left-left
        if (get_height(r->left) - get_height(r->right) == 2)
        {
            if (get_height(r->left->left) - get_height(r->left->right) ==  1)
            {
                AugTreeNode* tmp = r;
                AugTreeNode* new_root = r->left;
                if (r->parent == NULL)
                {
                    r = new_root;
                    new_root->parent = NULL;
                    new_root->is_left_child = true;
                }
                else if (r->is_left_child)
                {
                    r->parent->left = new_root;
                    new_root->parent = r->parent;
                    new_root->is_left_child = true;
                }
                else
                {
                    r->parent->right = new_root;
                    new_root->parent = r->parent;
                    new_root->is_left_child = false;
                }
                
                tmp->left = new_root->right;
                new_root->right = tmp;
                
                // update parent, height
                if (new_root->right->right != NULL)
                {
                    new_root->right->right->parent = new_root->right;
                    new_root->right->right->is_left_child = true;
                }
                
                new_root->right->height =
                    std::max(get_height(new_root->right->left),
                             get_height(new_root->right->right)) + 1;
                new_root->right->parant = new_root;
                new_root->right->is_left_child = false;
                
                new_root->height =
                    std::max(get_height(new_root->left), get_height(new_root->right))
                    + 1;
            } 
            else
            {
                AugTreeNode* left = r->left;
                AugTreeNode* left_right = r->left->right;

                r->left = left->right;
                left->right = left_right->left;
                left_right->left = left;
                
                if (left->right != NULL)
                {
                    left->right->parant = left;
                    left->right->is_left_child = false;
                }

                left->height = 
                    std::max(get_height(left->left), get_height(left->right))
                    + 1;
                left->parant = left_right;
                left->is_left_child = true;

                left_right->height = 
                    std::max(get_height(left_right->left),
                             get_height(left_right->right))
                    + 1;
                left_right->parant = r;
                left_right->is_left_child = true;
                
                balanceBST(r);
            }
        }
        else
        {
            if (get_height(r->right->left) - get_height(r->right->right) ==  -1)
            {
                AugTreeNode* tmp = r;
                AugTreeNode* new_root = r->right;
                if (r->parent == NULL)
                {
                    r = new_root;
                    new_root->parent = NULL;
                    new_root->is_left_child = true;
                }
                else if (r->is_left_child)
                {
                    r->parent->left = new_root;
                    new_root->parent = r->parent;
                    new_root->is_left_child = true;
                }
                else
                {
                    r->parent->right = new_root;
                    new_root->parent = r->parent;
                    new_root->is_left_child = false;
                }
                
                tmp->right = new_root->left;
                new_root->left = tmp;
                
                // update parent, height
                if (new_root->left->right != NULL)
                {
                    new_root->left->right->parent = new_root->left;
                    new_root->left->right->is_left_child = false;
                }
                
                new_root->left->height =
                    std::max(get_height(new_root->left->left),
                             get_height(new_root->left->right)) + 1;
                new_root->left->parant = new_root;
                new_root->left->is_left_child = true;
                
                new_root->height =
                    std::max(get_height(new_root->left),
                             get_height(new_root->right))
                    + 1;
            } 
            else
            {
                AugTreeNode* right = r->right;
                AugTreeNode* right_left = r->right->left;

                r->right = right_left;
                right->left = right_left->right;
                right_left->right = right;
                
                if (right->left != NULL)
                {
                    right->left->parant = right;
                    right->left->is_left_child = true;
                }

                right->height = 
                    std::max(get_height(right->left), get_height(right->right))
                    + 1;
                right->parant = right_left;
                right->is_left_child = false;

                right_left->height = 
                    std::max(get_height(right_left->left),
                             get_height(right_left->right))
                    + 1;
                right_left->parant = r;
                right_left->is_left_child = false;
                
                balanceBST(r);
            }
        }
    }
};

