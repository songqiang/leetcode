/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Write a function to find the longest common prefix string amongst an
array of strings.

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
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs.front();
        
        sort(strs.begin(), strs.end());
        pair<string::const_iterator, string::const_iterator> pp
            = mismatch(strs.front().begin(), strs.front().end(),
                       strs.back().begin());

        return strs.front().substr(0, pp.first - strs.front().begin());
    }
};


int
main(int argn, char** argv)
{
    Solution s;
}

