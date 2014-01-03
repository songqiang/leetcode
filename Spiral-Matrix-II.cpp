/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

Given an integer n, generate a square matrix filled with elements from
1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/

class Solution {
public:

    vector<vector<int> > generateMatrix(int n) {
        if (n == 0) return vector<vector<int> >();

        vector<vector<int> > res(n, vector<int>(n));        
        int step = n;
        int c = -1, r = 0;
        int val = 0;
        while (val < n*n)
        {
            for (int i = 0; i < step; ++i)
                res[r][++c] = ++val;

            for (int i = 0; i < step - 1; ++i)
                res[++r][c] = ++val;

            for (int i = 0; i < step - 1; ++i)
                res[r][--c] = ++val;

            for (int i = 0; i < step - 2; ++i)
                res[--r][c] = ++val;
            
            step -= 2;
        }
        
        return res;
        
    }

    vector<vector<int> > generateMatrix_loop_over_layer(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<vector<int> > m(n, vector<int>(n, 0));
        
        int n_layer = n / 2 + n % 2;

        int s = 1;
        for (int layer = 0; layer < n_layer; ++layer)
        {

            int row = layer;
            int col = layer;

            // top
            for (int i = 0; i < n - layer * 2; ++i)
                m[row][col++] = s++;

            // right
            --col;
            for (int i = 0; i < n - layer * 2 - 1; ++i)
                m[++row][col] = s++;

            // bottom
            for (int i = 0; i < n - layer * 2 - 1; ++i)
                m[row][--col] = s++;
            
            // left
            for (int i = 0; i < n - layer * 2 - 2; ++i)
                m[--row][col] = s++;
        }

        return m;
        
    }
};


