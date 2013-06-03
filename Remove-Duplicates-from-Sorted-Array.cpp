/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given a sorted array, remove the duplicates in place such that each
element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in
place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].

 */

#include <cmath>

#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <limits>
#include <utility>

using namespace std;


class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (n == 0) return 0;
        
        int i = 1;
        int j = 1;
        while (j < n)
        {
            if (A[j] == A[j - 1])
                ++j;
            else
                A[i++] = A[j++];
        }
        return i;

    }
};


int
main(int argn, char** argv)
{
    Solution s;
    int A[] = {1, 1, 2};
    int n = s.removeDuplicates(A, 3);
    for (size_t i = 0; i < n; ++i)
        cout << A[i] << "\t";
    cout << endl;
}

