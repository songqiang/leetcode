/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

Suppose a sorted array is rotated at some pivot unknown to you
beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return
its index, otherwise return -1.

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

*/


#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>
#include <algorithm>


using namespace std;

class Solution {
public:

    int
    binary_search_sorted(int A[], int h, int t, int target)
    {
        if (h >= t) return -1;
        if (h + 1 == t) return A[h] == target ? h : -1;

        const int m = (h + t - 1) / 2;
        if (A[m] < target)
            return binary_search_sorted(A, m + 1, t, target);
        else if (A[m] > target)
            return binary_search_sorted(A, h, m, target);
        else 
            return m;
    }

    int
    findMinIdx(int A[], int h, int t)
    {
        if (t == h + 1 ) return h;

        int m = (h + t - 1) / 2;
        
        if (A[m] > A[h] && A[m] < A[t - 1]
            || A[m] > A[h] && A[m] == A[t - 1]
            || A[m] == A[h] && A[m] < A[t - 1])
            return h;
        else if (A[m] > A[h] && A[m] > A[t - 1]
            || A[m] == A[h] && A[m] > A[t - 1])
            return findMinIdx(A, m + 1, t);
        else if (A[m] < A[h] && A[m] < A[t - 1]
            || A[m] < A[h] && A[m] == A[t - 1]
            || A[m] < A[h] && A[m] > A[t - 1])
            return findMinIdx(A, h, m + 1);
        else if (A[m] == A[h] && A[m] == A[t - 1])
        {
            const int f = A[m];
            const int idx = find_if(A + h, A + t, bind1st(not_equal_to<int>(), A[h])) - A;
            return idx == t ? h : findMinIdx(A, idx, t);
        }
    }
    
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        const int h = findMinIdx(A, 0, n);
        return target > A[n - 1] ? binary_search_sorted(A, 0, h, target) != -1
            : binary_search_sorted(A, h, n, target) != -1;

    }
};

int
main(int argn, char** argv)
{
    Solution s;
    int A[] = {4,5,6,7,0,1,2};
    cout << s.search(A, 7, 7) << endl;
}



