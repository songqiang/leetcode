/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given a string containing only digits, restore it by returning all
possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

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

using namespace std;

class Solution {
public:
    bool
    check_valid(const string& str)
    {
        const int i = atoi(str.c_str());
        return (!(str.size() > 1 && str[0] == '0')) && i >= 0 && i <= 255;
    }

    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        const int n = s.size();
        if (n < 4 || n > 12) return vector<string>();

        vector<string> results;

        vector<string> r(4);
        int used = 0;

        for (int n1 = max(1, n - 9);  n1 <= min(3, n - 3); ++n1)
        {
            r[0] = s.substr(0, n1);
            if (!check_valid(r[0])) continue;
            used += r[0].size();

            for (int n2 = max(1, n - used - 6); n2 <= min(3, n - used - 2); ++n2)
            {
                r[1] = s.substr(used, n2);
                if (!check_valid(r[1])) continue;
                used += r[1].size();
                
                for (int n3 = max(1, n - used - 3); n3 <= min(3, n - used - 1); ++n3)
                {
                    r[2] = s.substr(used, n3);
                    if (!check_valid(r[2])) continue;
                    used += r[2].size();

                    r[3] = s.substr(used, n - used);
                    if (check_valid(r[3]))
                    {
                        results.push_back(r[0] + "." + r[1] + "."
                                          + r[2] + "." + r[3]);
                    }
                    
                    used -= r[2].size();
                }
                used -= r[1].size();
            }
            used -= r[0].size();
        }

        return results;
    }
};


int
main(int argn, char** argv)
{
    Solution s;
}



