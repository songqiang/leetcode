/*
 * Song Qiang <keeyang@ustc.edu>
 */

/*

Given a string s and a dictionary of words dict, determine if s can be
segmented into a space-separated sequence of one or more dictionary
words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

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
#include <stack>
#include <functional>
#include <unordered_set>


using namespace std;

class Solution {
public:
    bool
    wordBreak(string s, unordered_set<string> &dict) {
        if (s.empty()) return true;

        vector<bool> good(s.size(), false);
        for (size_t i = 0; i < s.size(); ++i)
        {
            for (size_t j = i; j > 0 ; --j)
                if (good[j - 1] && dict.find(s.substr(j, i - j + 1)) != dict.end())
                {
                    good[i] = true;
                    break;
                }
            good[i] = good[i] || (dict.find(s.substr(0, i + 1)) != dict.end());
        }

        return good.back();
    }
};

int
main(int argn, char** argv)
{
    Solution s;
}

