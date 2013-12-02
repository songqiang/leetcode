/*
 * Song Qiang <keeyang@ustc.edu>
 */

/*

Given an array of integers, every element appears three times except
for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you
implement it without using extra memory?


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
#include <unordered_map>


using namespace std;

class Solution {
public:
    int
    singleNumber(int A[], int n) {

        int result = 0;
        for (size_t b = 0; b < 32; ++b)
        {
            int c = 0;
            for (size_t i = 0; i < n; ++i)
                c += (A[i] >> b) & 1;
            result |= (c % 3) << b;
        }
        return result;
    }
};


int
main(int argn, char** argv)
{
    Solution s;
}



