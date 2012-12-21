/*
 * Song Qiang <qiang.song@usc.edu> 2012
 */


/*

First missing positive 

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

 */

#include <vector>
#include <iostream>
#include <string>
#include <limits>

class Solution {
public:

    // hashing function
    int
    firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        for (size_t i = 0; i < n; ++i)
            if (A[i] <= 0) A[i] = std::numeric_limits<int>::max();

        for (size_t i = 0; i < n; ++i)
            if (abs(A[i]) <= n && abs(A[i]) >= 0)
                A[abs(A[i]) - 1] = -abs(A[abs(A[i]) - 1]);

        for (size_t i = 0; i < n; ++i)
            if (A[i] > 0) return i + 1;
        return n + 1;
    }
};
