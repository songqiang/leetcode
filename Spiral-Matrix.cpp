/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

Given a matrix of m x n elements (m rows, n columns), return all
elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int n_row = matrix.size();
        if (n_row == 0) return vector<int>();
        int n_col = matrix.front().size();
        if (n_col == 0) return vector<int>();

        int dim = min(n_row, n_col);
        
        int n_layer = dim % 2 + dim / 2;

        vector<int> r;

        for (int layer = 0; layer < n_layer; ++layer)
        {
            int row = layer;
            int col = layer;

            // top
            for (int i = 0; i < n_col - layer * 2; ++i)
                r.push_back(matrix[row][col++]);

            // right
            --col;
            for (int i = 0; i < n_row - layer * 2 - 1; ++i)
                r.push_back(matrix[++row][col]);
            

            // bottom
            if (n_row - layer * 2 - 1 > 0)
                for (int i = 0; i < n_col - layer * 2 - 1; ++i)
                    r.push_back(matrix[row][--col]);
            
            // left
            if (n_col - layer * 2 - 1> 0)
                for (int i = 0; i < n_row -  layer * 2 - 2; ++i)
                    r.push_back(matrix[--row][col]);
        }

        return r;
        
        
    }
};
