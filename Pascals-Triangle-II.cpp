/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

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
#include <unordered_set>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (rowIndex <= 0) return vector<int>(1,1);

        vector<int> v1(rowIndex + 1, 1);
        vector<int> v2(rowIndex + 1, 1);

        for (int r = 1; r < rowIndex + 1; ++r)
        {
            for (int i = 1; i < r + 1; ++i)
                v2[i] = v1[i] + v1[i-1];
            swap_ranges(v2.begin(), v2.begin() + r + 1, v1.begin());
        }

        return v2;

    }
};


int
main(int argn, char** argv)
{
    Solution s;
}

