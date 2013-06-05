/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given an array with n objects colored red, white or blue, sort them so
that objects of the same color are adjacent, with the colors in the
order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red,
white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

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
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int i = 0;
        int j = 0;
        while (j < n)
            if (A[j] == 0)
                swap(A[i++], A[j++]);
            else
                ++j;

        j = i;
        while (j < n)
            if (A[j] == 1)
                swap(A[i++], A[j++]);
            else
                ++j;
        
    }
};

int
main(int argn, char** argv)
{
    Solution s;
}

