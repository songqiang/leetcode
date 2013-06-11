/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given a set of distinct integers, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.  The solution
set must not contain duplicate subsets.

For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
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

using namespace std;


class Solution {
public:

    void
    subsets(const vector<int> &S, int i, vector<int> &r,
            vector<vector<int> > &results) 
    {
        if (i == S.size())
        {
            results.push_back(r);
            sort(results.back().begin(), results.back().end());
            return;
        }

        // not choose ith position
        subsets(S, i + 1, r, results);

        // choose ith position
        r.push_back(S[i]);
        subsets(S, i + 1, r, results);
        r.pop_back();
    }

    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<int> r;
        vector<vector<int> > results;
        subsets(S, 0, r, results);
        return results;
    }

};

int
main(int argn, char** argv)
{
    Solution s;
}

