/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given a 2D binary matrix filled with 0's and 1's, find the largest
rectangle containing all ones and return its area.

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
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <functional>


using namespace std;


class Solution {
public:

    struct BestRecord {
        int h, v;
        BestRecord(const int hor = 0, const int ver = 0) : h(hor), v(ver) {}
    };
        
    int
    maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        const int n_row = matrix.size();
        if (n_row == 0) return 0;

        const int n_col = matrix.front().size();
        if (n_col == 0) return 0;
        
        int area = 0;
        vector<vector<BestRecord> > rec(n_row, vector<BestRecord>(n_col));

        
        rec[0][0].h = rec[0][0].v = matrix[0][0] == '1';
        area = max(area, rec[0][0].h);

        for (int r = 1; r < n_row; ++r)
        {
            rec[r][0].v = matrix[r][0] == '1' ? (rec[r - 1][0].v + 1) : 0;
            rec[r][0].h = matrix[r][0] == '1';
            area = max(area, rec[r][0].v);
        }        

        for (int c = 1; c < n_col; ++c)
        {
            rec[0][c].h = matrix[0][c] == '1' ? (rec[0][c - 1].h + 1) : 0;
            rec[0][c].v = matrix[0][c] == '1';
            area = max(area, rec[0][c].h);
        }        

        for (int r = 1; r < n_row; ++r)
            for (int c = 1; c < n_col; ++c)
                if (matrix[r][c] == '1')
                {
                    rec[r][c].h = rec[r][c - 1].h + 1;
                    rec[r][c].v = rec[r - 1][c].v + 1;

                    int minv = numeric_limits<int>::max();
                    for (int i = c; i >= c + 1 - rec[r][c].h; --i)
                    {
                        minv = min(minv, rec[r][i].v);
                        area = max(area, minv * (c - i + 1));
                        cout << r << "\t" << c << "\t" << area << endl;
                    }
                }
                else
                {
                    rec[r][c].h = rec[r][c].v = 0;
                }
        

        return area;
    }
};


int
main(int argn, char** argv)
{
    vector<vector<char> > m({{'0', '1'}, {'0', '1'}});
    Solution s;
    cout << s.maximalRectangle(m) << endl;
    
}

