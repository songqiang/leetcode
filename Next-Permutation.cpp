/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

 Implement next permutation, which rearranges numbers into the
 lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the
lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

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
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if (num.size() <= 1) return;
		
		int i = num.size() - 2;
		while (i >= 0 && num[i] >= num[i + 1]) --i;
		reverse(num.begin() + i + 1, num.end());
		if (i >= 0)
			iter_swap(num.begin() + i, upper_bound(num.begin() + i + 1, num.end(), num[i]));

    }
};


int
main(int argn, char** argv)
{
	Solution s;
}

