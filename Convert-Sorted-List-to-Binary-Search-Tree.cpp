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



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> vals;
        ListNode* ptr = head;
        while (ptr != NULL)
        {	
            vals.push_back(ptr->val);
            ptr = ptr->next;
        } 

        return toBST(vals.begin(), vals.end());
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

