/*
 * Song Qiang <keeyang@ustc.edu>
 */

/*

There are N children standing in a line. Each child is assigned a
rating value.

You are giving candies to these children subjected to the following
requirements:

Each child must have at least one candy.  Children with a higher
rating get more candies than their neighbors.

What is the minimum candies you must give? 

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
#include <stack>
#include <functional>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {

        vector<int> hl(ratings.size(), 1), hr(ratings.size(), 1);
        
        for (size_t i = 1; i < ratings.size(); ++i)
            if (ratings[i] > ratings[i - 1])
                hl[i] = hl[i - 1] + 1;

        for (int i = ratings.size() - 1; i > 0; --i)
            if (ratings[i - 1] > ratings[i])
                hr[i - 1] = hr[i] + 1;
        
        int s = 0;
        for (size_t i = 0; i < ratings.size(); ++i)
            s += max(hl[i], hr[i]);

        return s;
    }
};


int
main(int argn, char** argv)
{
    Solution s;
}



