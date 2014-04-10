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
        if (strs.empty()) return "";

        int id = 0;
        while (true) {
            if (id == strs.front().size()) return strs.front().substr(0, id);
            for (int i = 1; i < strs.size(); ++i)
            {
                if (id == strs[i].size() || strs[i][id] != strs.front()[id])
                    return strs.front().substr(0, id);
            }
            ++id;
        }
        
        
        return "";
    }


    // alternative solution: without sorting
    string longestCommonPrefix(vector<string> &strs) {
        
        if (strs.empty()) return "";
        
        int n = numeric_limits<int>::max();
        for (int i = 0; i < strs.size(); ++i)
            n = min(n, int(strs[i].size()));
            
        for (int k = 0; k < n; ++k)
            for (int i = 1; i < strs.size(); ++i)
                if (strs[i][k] != strs[0][k])
                    return strs[0].substr(0, k);
        
        return strs[0].substr(0, n);
        
    }

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

