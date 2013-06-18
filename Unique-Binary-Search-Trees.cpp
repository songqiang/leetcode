/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given n, how many structurally unique BST's (binary search trees) that
store values 1...n?

For example,

Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

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
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<int> r(n + 1, 0);
        r[0] = 1;
        r[1] = 1;
        
        for (size_t i = 2; i < n + 1; ++i)
        {
            const int mid = i / 2;
            for (size_t root = 1; root <= mid; ++root)
                r[i] += 2 * r[root - 1] * r[i - root];

            if (i % 2 == 1)
                r[i] += r[mid] * r[mid];
        }

        return r[n];
        
        
    }
};


int
main(int argn, char** argv)
{
    Solution s;
}



