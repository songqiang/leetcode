/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given a number represented as an array of digits, plus one to the
number.

 */

#include <cmath>
#include <cstdlib>


#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <limits>
#include <utility>

using namespace std;

class Solution {
public:

    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<int> r(digits);

        const int n = r.size();
        int inc = 0;
        for (size_t i = 0; i < n; ++i)
        {
            r[n - 1 - i] += inc + (i == 0);
            inc  = r[n - 1 - i] / 10;
            r[n - 1 - i] %= 10;
            if (inc == 0) break;
        }

        if (inc > 0) r.insert(r.begin(), inc);

        return r;

    }

};

int
main(int argn, char** argv)
{
    Solution s ;
}

