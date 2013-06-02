/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a
challenge, please do not see below and ask yourself what are the
possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no
given input specs). You are responsible to gather all the input
requirements up front.
  

 */

#include <cmath>

#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <limits>


using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (x == 0) return true;
        if (x < 0) return false;

        const int max_n_digits = static_cast<int>(
            floor(log(numeric_limits<int>::max()) / log(10)) + 1);
        int n_digits = static_cast<int>(floor(log(x) / log(10)) + 1);

        vector<int> exp10(min(n_digits + 1, max_n_digits), 1);
        for (size_t i = 1; i < exp10.size(); ++i)
            exp10[i] = 10 * exp10[i - 1];

        // working with the highest digits for over-flow
        if (max_n_digits == n_digits)
        {
            const int h = x / 10^(n_digits - 1);
            const int l = x % 10;
            if (h != l) return false;
        }

            
        for (size_t i = (max_n_digits == n_digits); i < n_digits / 2; ++i)
        {
            const int h = (x % exp10[n_digits - i]) / exp10[n_digits - i  - 1];
            const int l = (x % exp10[i + 1]) / exp10[i];

            if (h != l) return false;
        }
        
        return true;
    }
};

int
main(int argn, char** argv)
{
    Solution s;
    cout << s.isPalindrome(789656987) << endl;
}

