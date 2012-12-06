/*
 * Song Qiang <qiang.song@usc.edu> 2012
 *
 */

/*

Container With Most Water

Given n non-negative integers a1, a2, ..., an, where each represents a
point at coordinate (i, ai). n vertical lines are drawn such that the
two endpoints of line i is at (i, ai) and (i, 0). Find two lines,
which together with x-axis forms a container, such that the container
contains the most water.

Note: You may not slant the container.

 */

class Solution {
public:
    int 
    maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (height.size() < 2) return 0;

        size_t h = 0, t = height.size() - 1;

        size_t best = 0;
        while (h < t)
        {
            best = std::max(best, (t - h) * std::min(height[h], height[t]));

            if (height[h] <= height[t])
                ++h;
            else
                --t;
        }

        return best;
    }
};
