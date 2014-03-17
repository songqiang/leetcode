/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

*/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int n = matrix.size();
        
        if (n <= 1) return;

        int n_layer = n / 2;
        for (int layer = 0; layer < n_layer; ++layer)
        {
            // number of elements
            const int num = n - layer * 2;
            
            // top left
            const int tlr = layer;
            const int tlc = layer;
            
            // top right
            const int trr = tlr;
            const int trc = tlc + num - 1;

            // bottom right
            const int brr = trr + num - 1;
            const int brc = trc;
            
            // bottom left
            const int blr = brr;
            const int blc = brc - (num - 1);
            
            for (int i = 0; i < num - 1; ++i)
            {
                const int tmp = matrix[tlr][tlc + i];

                matrix[tlr][tlc + i] = matrix[blr - i][blc];
                matrix[blr - i][blc] = matrix[brr][brc - i];
                matrix[brr][brc - i] = matrix[trr + i][trc];
                matrix[trr + i][trc] = tmp;
            }
        }


    }
};

