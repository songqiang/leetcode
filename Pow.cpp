/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Implement pow(x, n).


 */

#include <cmath>

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
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (fabs(x) < 1e-10) return n == 0 ? 1 : 0;

        if (x < 0)
            return n % 2 == 0 ? pow(-x, n) : -pow(-x, n);

        return exp(n * log(x));

    }
};


int
main(int argn, char** argv)
{
    Solution s;
}

