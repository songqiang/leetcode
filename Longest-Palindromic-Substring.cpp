/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given a string S, find the longest palindromic substring in S. You may
assume that the maximum length of S is 1000, and there exists one
unique longest palindromic substring.

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
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (s.empty()) return "";

        vector<int> palin1;
        vector<int> palin2;

        palin1.push_back(0);
        
        int ls = 0;
        int lmax = 1;

        for (int i = 1; i < s.size(); ++i)
        {
            palin2.push_back(i);
            if (s[i] == s[i - 1])
            {
                palin2.push_back(i - 1);
                if (i - palin2.back() + 1 > lmax)
                {
                    ls = palin2.back();
                    lmax = i - palin2.back() + 1;
                }
            }
            for (int j = 0; j < palin1.size(); ++j)
                if (palin1[j] - 1 >= 0
                    && s[palin1[j] - 1] == s[i])
                {
                    palin2.push_back(palin1[j] - 1);
                    if (i - palin2.back() + 1 > lmax)
                    {
                        ls = palin2.back();
                        lmax = i - palin2.back() + 1;
                    }
                }

            palin1.assign(palin2.begin(), palin2.end());
            palin2.clear();
        }

        return s.substr(ls, lmax);
        
    }
};


int
main(int argn, char** argv)
{
    Solution s;
    cout << s.longestPalindrome("ccc") << endl;
    
}

