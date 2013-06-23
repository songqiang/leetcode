/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given a 2D board containing 'X' and 'O', capture all regions
surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded
region .

For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

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
#include <queue>

using namespace std;



class Solution {
public:

    struct Cell 
    {
        int row, col; 
        Cell(int r, int c) : row(r), col (c) {}
    };
    
    void
    solve(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        const int n_row = board.size();
        if (n_row == 0) return;
        const int n_col = board.front().size();
        if (n_col == 0) return;
        
        queue<Cell> cells;
        for (size_t i = 0; i < n_row; ++i)
        {
            if (board[i][0] == 'O') cells.push(Cell(i, 0));
            if (board[i][n_col - 1] == 'O') cells.push(Cell(i, n_col - 1));
        }

        for (size_t i = 0; i < n_col; ++i)
        {
            if (board[0][i] == 'O') cells.push(Cell(0, i));
            if (board[n_row - 1][i] == 'O') cells.push(Cell(n_row - 1, i));
        }
        
        while (!cells.empty())
        {
            const Cell c = cells.front();
            cells.pop();

            board[c.row][c.col] = 'o';
            
            if (c.row + 1 < n_row
                && board[c.row + 1][c.col] == 'O')
                cells.push(Cell(c.row + 1, c.col));
            if (c.row - 1 >= 0
                && board[c.row - 1][c.col] == 'O')
                cells.push(Cell(c.row - 1, c.col));
            if (c.col + 1 < n_col
                && board[c.row][c.col + 1] == 'O')
                cells.push(Cell(c.row, c.col + 1));
            if (c.col - 1 >= 0
                && board[c.row][c.col - 1] == 'O')
                cells.push(Cell(c.row, c.col - 1));
        }

        for (int r = 0; r < n_row; ++r)
        {
            replace(board[r].begin(), board[r].end(), 'O', 'X');
            replace(board[r].begin(), board[r].end(), 'o', 'O');
        }
    }
    
};



int
main(int argn, char** argv)
{
    Solution s;
}

