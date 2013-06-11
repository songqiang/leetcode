/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent
cell, where "adjacent" cells are those horizontally or vertically
neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

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

    bool
    exist(const vector<vector<char> > &board,
          vector<vector<bool> > &visited,
          const string &word,
          const int i,
          const int r,
          const int c)
    {
        if (i == word.size())
            return true;

        if (r >= board.size() || c >= board.front().size() || r < 0 || c < 0)
            return false;

        if (visited[r][c] || board[r][c] != word[i])
            return false;

        visited[r][c] = true;
        const bool found = exist(board, visited, word, i + 1, r + 1, c)
            || exist(board, visited, word, i + 1, r - 1, c)
            || exist(board, visited, word, i + 1, r, c + 1)
            || exist(board, visited, word, i + 1, r, c - 1);
        visited[r][c] = false;

        return found;
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (word.empty()) return true;
        const int n_row = board.size();
        if (n_row == 0) return false;
        const int n_col = board.front().size();
        if (n_col == 0) return false;
        
        vector<vector<bool> > visited(n_row, vector<bool>(n_col, false));
                 
        for (size_t r = 0; r < board.size(); ++r)
            for (size_t c = 0; c < board.front().size(); ++c)
                if (board[r][c] == word[0])
                {
                    const bool found = exist(board, visited, word, 0, r, c);
                    if (found) return found;
                }

        return false;
    }

};


int
main(int argn, char** argv)
{
    Solution s;
}

