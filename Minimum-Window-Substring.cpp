/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given a string S and a string T, find the minimum window in S which
will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note: If there is no such window in S that covers all characters in T,
return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will
always be only one unique minimum window in S.

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
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<int> tcounts(128, 0);
        for_each(T.begin(), T.end(), [&tcounts](const char c) {++tcounts[c];});
        const int tc = T.size();
        
        vector<int> wcounts(128, 0);
        int besth, bestw = numeric_limits<int>::max();
        
        int h = 0, t = 0;
        int wc = 0;

        while (t < S.size())
        {	
            ++wcounts[S[t]];
            wc += wcounts[S[t]] <= tcounts[S[t]];
            ++t;
            if (wc == tc)
            {
                while (wc == tc)
                {
                    wc -= wcounts[S[h]] <= tcounts[S[h]];
                    --wcounts[S[h]];
                    ++h;
                }
                if (t - h + 1 < bestw)
                {
                    besth = h - 1;
                    bestw = t - h + 1;
                }
            }
        } 

        return S.substr(besth, bestw == numeric_limits<int>::max() ? 0 : bestw);
    }
};

int
main(int argn, char** argv)
{
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
}

