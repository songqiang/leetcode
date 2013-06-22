/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

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
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (numRows <= 0) return vector<vector<int> >();

        vector<vector<int> > results(1, vector<int>(1, 1));
        for (int l = 2; l < numRows + 1; ++l)
        {
            results.push_back(vector<int>(l, 1));
            for (int i = 1; i < l - 1; ++i)
                results[l-1][i] = results[l-2][i-1] + results[l-2][i];
        }

        return results;
    }
};


int
main(int argn, char** argv)
{
    Solution s;
}

