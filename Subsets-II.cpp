/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given a collection of integers that might contain duplicates, S,
return all possible subsets.

Note:

Elements in a subset must be in non-descending order.  The solution
set must not contain duplicate subsets.  For example,

If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
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
    subsets(const vector<int> &num, const vector<int> &counts,
            int i, vector<int> &r, vector<vector<int> > &results) 
    {
        if (i == num.size())
        {
            results.push_back(r);
            return;
        }

        // not choose ith number
        subsets(num, counts, i + 1, r, results);

        for (size_t n = 0; n < counts[i]; ++n)
        {
            r.push_back(num[i]);
            subsets(num, counts, i + 1, r, results);
        }

        // choose ith position
        r.erase(r.end() - counts[i], r.end());
    }

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (S.size() == 0) return vector<vector<int> >(1, vector<int>());
        
        sort(S.begin(), S.end());
        
        vector<int> num;
        vector<int> count;
        num.push_back(S.front());
        count.push_back(1);
        
        for (size_t i = 1; i < S.size(); ++i)
            if (S[i] == num.back())
                ++count.back();
            else
            {
                num.push_back(S[i]);
                count.push_back(1);
            }
        
        vector<int> r;
        vector<vector<int> > results;
        subsets(num, count, 0, r, results);
        return results;
        
    }

};

int
main(int argn, char** argv)
{
    Solution s;
}

