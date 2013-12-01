/*
 * Song Qiang <keeyang@ustc.edu>
 */

/*

Sort List

Sort a linked list in O(n log n) time using constant space complexity.

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

void 
quick_sort(vector<int> &v, size_t left, size_t right)
{
    if (right - left <= 1) return;

    const int pivot = v[(left + right - 1) / 2];

    size_t s = left;
    size_t t = right - 1;
    while (s < t)
    {
        while (v[s] < pivot) ++s;
        while (v[t] > pivot) --t;
        swap(v[s], v[t]);
        ++s;
    }
    quick_sort(v, left, s);
    quick_sort(v, s, right);
}

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

    ListNode*
    quick_sortList(ListNode *head)
    {
        if (head == NULL || head ->next == NULL) return head;
        
        const int pivot = head->val;
        
        ListNode *hs = new ListNode(0);
        ListNode *hg = new ListNode(0);
        ListNode *he = new ListNode(0);
        
        ListNode *ts = hs;
        ListNode *tg = hg; 
        ListNode *te = he;
       
        while (head != NULL)
        {
            if (head->val < pivot)
            {
                ts->next = head;
                head = head->next;
                ts = ts->next;
                ts->next = NULL;
            }
            else if (head->val > pivot)
            {
                tg->next = head;
                head = head->next;
                tg = tg->next;
                tg->next = NULL;
            }
            else
            {
                te->next = head;
                head = head->next;
                te = te->next;
                te->next = NULL;
            }
        }

        remove_head(hg);
        remove_head(hs);
        remove_head(he);

        hs = quick_sortList(hs);
        hg = quick_sortList(hg);

        // printList(hs);
        // printList(he);
        // printList(hg);

        ListNode* t = he;
        while (t->next != NULL) t = t->next;
        t->next = hg;

        if (hs == NULL)
            return he;
        else
        {
            ListNode* t = hs;
            while (t->next != NULL) t = t->next;
            t->next = he;
            return hs;
        }
    }

    ListNode *sortList(ListNode *head)
    {
        return quick_sortList(head);
    }
};

int
main(int argn, char** argv)
{
    ListNode* h = new ListNode(2);
    h->next = new ListNode(1);
    Solution s;
    s.printList(h);
    h = s.sortList(h);
    s.printList(h);
    s.clearList(h);
}
