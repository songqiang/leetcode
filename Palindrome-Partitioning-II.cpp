/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given a string s, partition s such that every substring of the
partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",

Return 1 since the palindrome partitioning ["aa","b"] could be
produced using 1 cut.

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
#include <functional>


using namespace std;

class Solution {
public:
    
    int
    minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (s.empty()) return 0;
        

        vector<int> best(s.size(), numeric_limits<int>::max());
        vector<int> palin1, palin2;

        palin1.push_back(0);
        best[0] = 0;
        
        for (int i = 1; i < s.size(); ++i)
        {
            palin2.push_back(i);
            best[i] = min(best[i], best[i - 1] + 1);

            if (s[i] == s[i - 1])
            {
                palin2.push_back(i - 1);
                best[i] = min(best[i], i - 2 >= 0 ? best[i - 2] + 1 : 0);
            }
            
            for (int j = 0; j < palin1.size(); ++j)
                if (palin1[j] - 1 >= 0
                    && s[palin1[j] - 1] == s[i])
                {
                    palin2.push_back(palin1[j] - 1);
                    best[i] = min(best[i],
                                  palin2.back() - 1 >= 0
                                  ? best[palin2.back() - 1] + 1 : 0);
                }

            palin1.assign(palin2.begin(), palin2.end());
            palin2.clear();
        }

        return best.back();
    }

};


int
main(int argn, char** argv)
{
    Solution s;
}

