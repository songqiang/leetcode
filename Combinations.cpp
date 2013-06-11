/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given two integers n and k, return all possible combinations of k
numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

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
    void combine(const int s, const int n, const int i,
                 vector<int> &r, vector<vector<int> > &result)
    {
        if (i == r.size())
        {
            result.push_back(r);
            return;
        }
        
        for (int k = s; k <= n + 1 + i - r.size(); ++k)
        {
            r[i] = k;
            combine(k + 1, n, i + 1, r, result);
        }
    }

    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<int> r(k);
        vector<vector<int> > result;
        combine(1, n, 0, r, result);
        return result;
    }

};

int
main(int argn, char** argv)
{
    Solution s;
    s.combine(1, 1);
}

