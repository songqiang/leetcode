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

#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        const char* p = str;
        if (*p == '\0') return 0;

        while (*p == ' ' || *p == '\9') ++p;

        int sign = 1;
        if (*p == '+') {++p;};
        if (*p == '-') {++p; sign = -1;};

        unsigned int s = 0;
        while (*p != '\0' && isdigit(*p))
        {
            if (s > numeric_limits<unsigned int>::max() / 10)
                return sign == 1 ? numeric_limits<int>::max()
                    : numeric_limits<int>::min();
            s *= 10;
            s += *p - 48;
            if (s > numeric_limits<int>::max())
                return sign == 1 ? numeric_limits<int>::max()
                    : numeric_limits<int>::min();
            ++p;
        }

        if (s > numeric_limits<int>::max())
            return sign == 1 ? numeric_limits<int>::max()
                : numeric_limits<int>::min();
        else
            return  static_cast<int>(sign * s);
    }
};


int
main(int argn, char** argv)
{
    Solution s;
}


// 2147483647
// 10522545459/
// 1932610867
