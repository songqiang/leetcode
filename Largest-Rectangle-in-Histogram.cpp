/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given n non-negative integers representing the histogram's bar height
where the width of each bar is 1, find the area of largest rectangle
in the histogram.

Above is a histogram where width of each bar is 1, given height =
[2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10
unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

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
#include <stack>

using namespace std;

// dynamic programming: cannot pass largest dataset
class Solution {
public:
    struct BestRec {
        int height, area;
        BestRec(const int h = 0, const int a = 0) : height(h), area(a) {}
    };

    int
    largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (height.empty()) return 0;

        vector<BestRec> rec1, rec2;
        rec1.push_back(BestRec(height[0], height[0]));
        int area = rec1.back().area;

        for (int i = 1; i < height.size(); ++i)
        {
            if (height[i] == 0) 
            {
                rec1.clear();
                continue;
            }
            
            int j = 0;
            while (j < rec1.size() && rec1[j].height < height[i])
            {
                rec2.push_back(BestRec(rec1[j].height,
                                       rec1[j].area + rec1[j].height));
                area = max(area, rec2.back().area);
                ++j;
            }

            if (j < rec1.size())
            {
                rec2.push_back(
                    BestRec(height[i],
                            height[i] * (rec1[j].area / rec1[j].height + 1)));
                area = max(area, rec2.back().area);
            }
            else
            {
                rec2.push_back(BestRec(height[i], height[i]));
                area = max(area, rec2.back().area);
            }
            
            swap(rec1, rec2);
            rec2.clear();
        }

        return area;
    }
};

// algorithm based on stack:
// http://fisherlei.blogspot.com/2012/12/leetcode-largest-rectangle-in-histogram.html
class MySolution {
public:
    int
    largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (height.empty()) return 0;

        vector<int> h(height.size() + 1);
        vector<int> w(height.size() + 1);

        int area = 0;
        int top = 0;

        for (size_t i = 0; i < height.size(); ++i)
        {
            int s = 0;
            while (top > 0 && h[top - 1] > height[i])
            {
                area = max(area, (w[top - 1] + s) * h[top - 1]);
                s += w[top - 1];
                --top;
            }

            if (top == 0 || h[top - 1] < height[i])
            {
                h[top] = height[i];
                w[top] = 1 + s;
                ++top;
            }
            else
                w[top - 1] += s + 1;
        }

        int s = 0;
        while (top > 0)
        {
            area = max(area, (w[top - 1] + s) * h[top - 1]);
            s += w[top - 1];
            --top;
        }
            
        return area;
    }
};

int
main(int argn, char** argv)
{
    vector<int> v({4,2,0,3,2,5});
    Solution s;
    cout << s.largestRectangleArea(v) << endl;
}

