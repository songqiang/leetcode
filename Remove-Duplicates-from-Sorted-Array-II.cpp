/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].

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

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int i = 0;
        int j = 0;
        while (j < n)
        {
            int k = j + 1;
            while (k < n && A[k] == A[j]) ++k;
            if (k - j >= 2) 
            {
                A[i++] = A[j];
                A[i++] = A[j];
            }
            else
                A[i++] = A[j];
            j = k;
        }

        return i;

    }
};


int
main(int argn, char** argv)
{
    Solution s;
}

