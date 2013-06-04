/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given a m x n matrix, if an element is 0, set its entire row and
column to 0. Do it in place.

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


    // O(m + n) space complexity
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        const int n_row = matrix.size();
        const int n_col = matrix.front().size();
        
        vector<bool> r(n_row, false);
        vector<bool> c(n_col, false);
        
        for (size_t i = 0; i < n_row; ++i)
            for (size_t j = 0; j < n_col; ++j)
                if (matrix[i][j] == 0)
                    r[i] = c[j] = true;

        for (size_t i = 0; i < n_row; ++i)
            for (size_t j = 0; j < n_col; ++j)
                if (r[i] || c[j])
                    matrix[i][j] = 0;

    }
};



int
main(int argn, char** argv)
{
    Solution s;
}

