/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from
top left to bottom right which minimizes the sum of all numbers along
its path.

Note: You can only move either down or right at any point in time.

*/

////////////////////////////////////////////
/////  RUNTIME ERROR
////////////////////////////////////////////


// dynamic programming
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function


        int n_row = grid.size();
        int n_col = grid.front().size();
        
        vector<vector<int> > result(n_row, vector<int>(n_col, 0));

        result[0][0] = grid[0][0];
        for (int i = 1; i < n_row; ++i)
            result[i][0] = grid[i][0] + result[i - 1][0];

        for (int j = 1; j < n_col; ++j)
            result[0][j] = grid[0][j] + result[0][j - 1];

        for (int i = 0; i < n_row; ++i)
        {
            for (int c = 1; c < min(i, n_col); ++c)
            {
                int r = i - c;
                result[r][c] = grid[r][c] + min(result[r-1][c], result[r][c-1]);
            }
        }

        for (int i = n_row; i < n_row + n_col - 1; ++i)
        {
            for (int r = max(1, i - n_col + 1); r < n_row; ++r)
            {
                int c = i - r;
                result[r][c] = grid[r][c] + min(result[r-1][c], result[r][c-1]);
            }
        }

        return result[n_row - 1][n_col - 1];
    }
};

