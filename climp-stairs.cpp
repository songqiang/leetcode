/*
 * 3sum: http://www.leetcode.com/2010/04/finding-all-unique-triplets-that-sums.html
 * Song Qiang <qiang.song@usc.edu> 2012-10-04
 *
 */

// time complexity: O(n^2)

/*

Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

*/

class Solution {
public:
    int
    climbStairs(int n) {
    // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;

        size_t back_two_step = 1;
        size_t back_one_step = 2;
        size_t r;

        for (size_t i = 3; i <= n; ++i)
        {
            r = back_one_step + back_two_step;
            back_two_step = back_one_step;
            back_one_step = r;
        }

        return r;
    }
};

