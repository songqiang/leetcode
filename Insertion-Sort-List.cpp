/*
 * Song Qiang <keeyang@ustc.edu>
 */

/*

Sort List

Sort a linked list using insertion sort.

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

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:

    void
    printList(ListNode* h)
    {
        ListNode* t = h;
        while (t != NULL)
        {
            cout << t->val << "\t";
            t = t->next;
        }
        cout << endl;
    }

    void
    clearList(ListNode* h)
    {
        while (h != NULL)
        {
            ListNode* t = h->next;
            delete h;
            h = t;
        }
    }

    void remove_head(ListNode* &head)
    {
        ListNode* t = head;
        head = head->next;
        delete t;
    }


    ListNode *insertionSortList(ListNode *head)
    {
        ListNode* h = ListNode(std::numeric_limits<int>::min());
        
        while (head != NULL)
        {
            ListNode* t = head;
            head = head->next;

            ListNode* p = h;
            while (p->next != NULL && p->next->val < t->val) p = p->next;
            t->next = p->next;
            p->next = t;
        }
        remove_head(h);
        return h;
    }
};

int
main(int argn, char** argv)
{
    ListNode* h = new ListNode(2);
    h->next = new ListNode(1);
    Solution s;
    s.printList(h);
    h = s.insertionSortList(h);
    s.printList(h);
    s.clearList(h);
}
