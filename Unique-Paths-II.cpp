/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique
paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the
grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated
below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

*/

#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {

        int n_row  = obstacleGrid.size();
        if (n_row == 0) return 0;
        int n_col = obstacleGrid.front().size();
        if (n_col == 0) return 0;
        vector<vector<int> > counts(n_row, vector<int>(n_col, 0));

        counts[0][0] = obstacleGrid[0][0] != 1;
        for (int c = 1; c < n; ++c)
            if (!obstacleGrid[0][c]) counts[0][c] = counts[0][c-1];
        for (int r = 1; r < m; ++r)
        {
            if (!obstacleGrid[r][0])
                counts[r][0] = counts[r-1][0];

            for (int c = 1; c < n; ++c)
                if (!obstacleGrid[r][c])
                    counts[r][c] = counts[r-1][c] + counts[r][c-1];
        }
        
        return counts.back().back();
    }
    

    int uniquePathsWithObstacles_DIAGONAL(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int n_row  = obstacleGrid.size();
        int n_col = obstacleGrid.front().size();
        vector<vector<int> > counts(n_row, vector<int>(n_col, 0));
        
        counts[0][0] = (!obstacleGrid[0][0]) * 1;

        for (int r = 1; r < n_row; ++r)
            counts[r][0] = (!obstacleGrid[r][0]) * counts[r-1][0];
        
        for (int c = 1; c < n_col; ++c)
            counts[0][c] = (!obstacleGrid[0][c]) * counts[0][c-1];

        for (int i = 0; i < n_row; ++i)
            for (int c = 1; c < min(i, n_col); ++c)
            {
                int r = i - c;
                counts[r][c] = (!obstacleGrid[r][c])*(counts[r-1][c] + counts[r][c-1]);
            }

        for (int i = n_row; i < n_row + n_col - 1; ++i)
            for (int r = max(1, i - n_col + 1); r < n_row; ++r)
            {
                int c = i - r;
                counts[r][c] = (!obstacleGrid[r][c])*(counts[r-1][c] + counts[r][c-1]);
            }

        return counts[n_row-1][n_col-1];

    }
};





