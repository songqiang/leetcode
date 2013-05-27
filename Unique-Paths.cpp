/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

A robot is located at the top-left corner of a m x n grid (marked
'Start' in the diagram below).

The robot can only move either down or right at any point in time. The
robot is trying to reach the bottom-right corner of the grid (marked
'Finish' in the diagram below).

How many possible unique paths are there?

*/

#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int n_row  = m;
        int n_col = n;
        vector<vector<int> > counts(n_row, vector<int>(n_col, 0));
        
        counts[0][0] = 1;

        for (int r = 1; r < n_row; ++r)
            counts[r][0] = 1;
        
        for (int c = 1; c < n_col; ++c)
            counts[0][c] = 1;

        for (int i = 0; i < n_row; ++i)
            for (int c = 1; c < min(i, n_col); ++c)
            {
                int r = i - c;
                counts[r][c] = counts[r-1][c] + counts[r][c-1];
            }

        for (int i = n_row; i < n_row + n_col - 1; ++i)
            for (int r = max(1, i - n_col + 1); r < n_row; ++r)
            {
                int c = i - r;
                counts[r][c] = counts[r-1][c] + counts[r][c-1];
            }

        return counts[n_row-1][n_col-1];
    }
};


int
main(int argn, char** argv)
{
    Solution s;
    cout << s.uniquePaths(1, 2) << endl;
}



