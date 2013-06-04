/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Implement int sqrt(int x).

Compute and return the square root of x.

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
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		assert(x >= 0);
		
		if (x == 0) return 0;
		
		int h = 46340; // deal with the largest integer
		int l = 0;
		while (h >= l)
		{
			const int mid = (h + l) / 2;
			const int ms = mid * mid;
			if (ms < x)
				l = mid + 1;
			else if (ms > x)
				h = mid - 1;
			else
				return mid;
		}
		
		return h;

    }
};





int
main(int argn, char** argv)
{
    Solution s;
}

