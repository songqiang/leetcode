/*
 * Song Qiang <qiang.song@usc.edu> 2012
 */


/*

Gray Code

The gray code is a binary numeral system where two successive values
differ in only one bit.

Given a non-negative integer n representing the total number of bits
in the code, print the sequence of gray code. A gray code sequence
must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to
the above definition.

For now, the judge is able to judge based on one instance of gray code
sequence. Sorry about that.


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
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (n == 0) return vector<int>(1, 0);

        int s = 0;
        for (size_t i = 0; i < n; ++i)
        {
            s <<= 1;
            s += 1;
        }

        vector<bool> visited(s + 1, false);
        vector<int> results;
        
        int curr = 0;
        visited[curr] = true;
        results.push_back(curr);

        for (size_t i = 0; i < s; ++i)
        {
            int next = curr, j = 0;
            while (j < n && visited[next])
            {
                next = curr ^ (1 << j);
                ++j;
            }
            if (j <= n)
            {
                curr = next;
                visited[curr] = true;
                results.push_back(curr);
            }
            else
                break;
        }

        return results;
        
    }
};

int
main(int argn, char** argv)
{
    Solution s;
    s.grayCode(2);
}


