/*
 * Song Qiang <keeyang@ustc.edu>
 */

/*

Given an array of integers, every element appears twice except for
one. Find that single one.

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

    // use XOR
    int
    singleNumber(int A[], int n) {

        while (--n) A[n - 1] ^= A[n];
        return A[0];



    }
};

int
main(int argn, char** argv)
{
    Solution s;
}



