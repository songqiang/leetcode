/*
 * Song Qiang <qiang.song@usc.edu> 2012
 *
 */

/*


 */

/*

Insert into a Cyclic Sorted List

http://www.leetcode.com/2011/08/insert-into-a-cyclic-sorted-list.html

Given a node from a cyclic linked list which has been sorted, write a
function to insert a value into the list such that it remains a cyclic
sorted list. The given node can be any single node in the list.

*/

struct Node 
{
    int val;
    Node* next;
    Node(const int v) : val(v), next(NULL);
};

class Solution {
public:
    Node*
    insertToSortedList(Node* ptr, const int v) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (ptr == NULL)
        {
            Node* p = new Node(v);
            p->next = p;
            return p;
        }
        
        while (!(ptr->val <= v && v <= ptr->next->val 
                 || ptr->val < v && ptr->val > ptr->next->val
                 || ptr->val > v && ptr->val > ptr->next->val))
            ptr = ptr->next;
        
        Node* p =  new Node(v);
        p->next = ptr->next;
        ptr->next = p;
        return ptr;
    }
};


