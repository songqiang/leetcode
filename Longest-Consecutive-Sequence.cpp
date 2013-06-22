/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given an unsorted array of integers, find the length of the longest
consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],

The longest consecutive elements sequence is [1, 2, 3, 4]. Return its
length: 4.

Your algorithm should run in O(n) complexity.

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

using namespace std;


// sorting based algo, but not linear
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (num.size() == 0) return 0;

        sort(num.begin(), num.end());
        
        int h = num.front();
        int t = num.front() + 1;
        int best = 1;
        for (size_t i = 1; i < num.size(); ++i)
        {
            if (num[i] == t)
                ++t;
            else if (num[i] > t)
            {
                best = max(best, t - h);
                h = num[i];
                t = h + 1;
            }
        }
        best = max(best, t - h);

        return best;

    }
};


int
main(int argn, char** argv)
{
    Solution s;
}

