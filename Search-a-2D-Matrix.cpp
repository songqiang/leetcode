/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Write an efficient algorithm that searches for a value in an m x n
matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.  The first integer
of each row is greater than the last integer of the previous row.  For
example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.


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
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        const int n_row = matrix.size();
        if (n_row == 0) return false;
        const int n_col = matrix.front().size();
        if (n_col == 0) return false;
        
        vector<int> first_col(n_row);
        for (size_t i = 0; i < n_row; ++i)
            first_col[i] = matrix[i][0];

        const vector<int>::const_iterator ub
            = upper_bound(first_col.begin(), first_col.end(), target);
        const int r
            = ub == first_col.begin() ? 0 : ub - first_col.begin() - 1;
        
        const vector<int>::const_iterator lb
            = lower_bound(matrix[r].begin(), matrix[r].end(), target);

        return lb < matrix[r].end() && *lb == target;
    }
    
};


int
main(int argn, char** argv)
{
    Solution s;
}

