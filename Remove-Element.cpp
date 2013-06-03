/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given an array and a value, remove all instances of that value in
place and return the new length.

The order of elements can be changed. It doesn't matter what you leave
beyond the new length.

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
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		int i = 0;
		int j = 0;
		while (j < n)
			if (A[j] != elem)
				A[i++] = A[j++];
			else
				++j;
		return i;
    }
};


int
main(int argn, char** argv)
{
    Solution s;
}

