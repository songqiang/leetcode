/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

Suppose a sorted array is rotated at some pivot unknown to you
beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return
its index, otherwise return -1.

You may assume no duplicate exists in the array.

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
        if (h > t) return -1;
        if (h == t) return A[h] == target ? h : -1;

        const int m = (h + t) / 2;
        if (A[m] < target)
            return binary_search_sorted(A, m + 1, t, target);
        else if (A[m] > target)
            return binary_search_sorted(A, h, m - 1, target);
        else 
            return m;
    }

    int
    binary_search_sorted_rot(int A[], int h, int t, int target)
    {
        if (t - h <= 3)
        {
            for (size_t i = h; i < t + 1; ++i)
                if (A[i] == target) return i;
        
            return -1;
        }

        int m = (h + t) / 2;
        if (A[m] == target) return m;
        
        if (A[m] > A[h] && A[m] < A[t])
        {
            if (A[m] < target)
                return binary_search_sorted(A, m + 1, t, target);
            else
                return binary_search_sorted(A, h, m - 1, target);
        }
        else if (A[m] > A[h] && A[m] > A[t])
        {
            if (A[m] < target)
                return binary_search_sorted_rot(A, m + 1, t, target);
            else
                return max(binary_search_sorted(A, h, m - 1, target),
                           binary_search_sorted_rot(A, m + 1, t, target));
        }
        else if (A[m] < A[h] && A[m] < A[t])
        {
            if (A[m] < target)
                return max(binary_search_sorted_rot(A, h, m - 1, target),
                           binary_search_sorted(A, m + 1, t, target));
            else
                return binary_search_sorted_rot(A, h, m - 1, target);
        }
    }
    
    
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        return binary_search_sorted_rot(A, 0, n - 1, target);
    }



};

// range close open
class MySolution {
public:

    int
    binary_search(int A[], int h, int t, int target)
    {
        while (h < t)
        {
            const int m = (h + t - 1) / 2;
            if (A[m] < target)
                h = m + 1;
            else if (A[m] > target)
                t = m;
            else 
                return m;
        }
        return -1;
    }

    int
    findMinIdx(int A[], int h, int t)
    {
        if (t == h + 1 ) return h;

        int m = (h + t - 1) / 2;
        
        if (A[m] > A[h] && A[m] < A[t - 1])
            return h;
        else if (A[m] > A[h] && A[m] > A[t - 1])
            return findMinIdx(A, m + 1, t);
        else if (A[m] < A[h] && A[m] < A[t - 1])
            return findMinIdx(A, h, m + 1);
    }
    
    int
    search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        const int h = findMinIdx(A, 0, n);
        return target > A[n - 1]
            ? binary_search(A, 0, h, target)
            : binary_search(A, h, n, target);
    }
};



int
main(int argn, char** argv)
{
    Solution s;
    int A[] = {5,1,2,3,4};
    cout << s.search(A, 5, 1) << endl;
}



