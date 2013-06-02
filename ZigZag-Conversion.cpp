/*
 * zigzag conversion:
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given
number of rows like this: (you may want to display this pattern in a
fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given
a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

 */

#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <sstream>

using namespace std;



class Solution 
{
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int n_col = 0;
        switch (nRows)
        {
        case 0: return ""; break;
        case 1: return s; break;
        case 2: n_col = s.size() / 2 + 1; break;
        default: n_col = (s.size() / (2 * nRows - 2) + 1) * (nRows - 1);
        } 

        vector<vector<char> > m(nRows, vector<char>(n_col, '\0'));
        int i = 0;
        int r = 0;
        int c = 0;
        while (i < s.size())
        {
            // go down
            int n_char = min(nRows, int(s.size() - i));
            for (int j = 0; j < n_char; ++j)
                m[r++][c] = s[i++];

            
            // go up
            r -= 2;
            c += 1;
            n_char = min(nRows - 2, int(s.size() - i));
            for (int j = 0; j < n_char; ++j)
                m[r--][c++] = s[i++];
        }

        ostringstream oss;
        for (size_t i = 0; i < m.size(); ++i)
            for (size_t j = 0; j < m.front().size(); ++j)
                if (m[i][j] != '\0')
                    oss << m[i][j];

        return oss.str();


    }

};


int
main(int argn, char** argv)
{
    Solution s;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
}

