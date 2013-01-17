/*
 * Song Qiang <qiang.song@usc.edu> 2012
 */


/*

Triangle

Given a triangle, find the minimum path sum from top to bottom. Each
step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space,
where n is the total number of rows in the triangle.

 */

// dynamic programming
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

       if (triangle.size() == 0) return 0;
        if (triangle.size() == 1) return triangle[0][0];

        vector<int> v(triangle.back());
        vector<int> u(triangle.back().size(), 0);
        
        for (int r = triangle.size() - 2; r >= 0; --r)
        {
            std::fill(u.begin(), u.begin() + r + 1, 0); 
            for (size_t i = 0; i < r + 1; ++i)
                u[i] = triangle[r][i] + std::min(v[i], v[i + 1]);

            std::copy(u.begin(), u.begin() + r + 1, v.begin()); 
        }

        return u[0];
    }
};
