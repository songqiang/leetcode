/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The
Rules.

The Sudoku board could be partially filled, where empty cells are
filled with the character '.'.

A partially filled sudoku which is valid.

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
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        // check row
        for (int r = 0; r < 9; ++r) {
            vector<bool> v(9, false);
            
            for (int c = 0; c < 9; ++c) 
                if (board[r][c] != '.')  {
                    if (v[board[r][c] - '1']) return false;
                    v[board[r][c] - '1'] = true;
                }
        }
        
        // check column
        for (int c = 0; c < 9; ++c) {
            vector<bool> v(9, false);
            
            for (int r = 0; r < 9; ++r) 
                if (board[r][c] != '.')  {
                    if (v[board[r][c] - '1']) return false;
                    v[board[r][c] - '1'] = true;
                }
        }
        
        // check block
        for (int br = 0; br < 3; ++br) 
            for (int bc = 0; bc < 3; ++bc) {
                vector<bool> v(9, false);

                for (int r = 0; r < 3; ++r) 
                    for (int c = 0; c < 3; ++c) 
                        if (board[br * 3 + r][bc * 3 + c] != '.')  {
                            if (v[board[br * 3 + r][bc * 3 + c] - '1']) return false;
                            v[board[br * 3 + r][bc * 3 + c] - '1'] = true;
                        }
            }

        return true;
    }
};


int
main(int argn, char** argv)
{
    Solution s;
}



"53..7....",
"6..195...",
".98....6.",
"8...6...3",
"4..8.3..1",
"7...2...6",
".6....28.",
"...419..5",
"....8..79"]
