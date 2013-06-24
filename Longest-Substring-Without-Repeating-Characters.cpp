/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

Given a string, find the length of the longest substring without
repeating characters. For example, the longest substring without
repeating letters for "abcabcbb" is "abc", which the length is 3. For
"bbbbb" the longest substring is "b", with the length of 1.


*/

#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <map>


using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (s.empty()) return 0;
        
        vector<int> start(s.size());

        map<char, int> occur;
        start[0] = 0;
        occur[s[0]] = 0;
        for (int i = 1; i < s.size(); ++i)
        {

            start[i] =
                max(start[i - 1],
                    occur.find(s[i]) == occur.end() ? 0 : (occur[s[i]] + 1));
            occur[s[i]] = i;
        }
        
        int best = 1;
        for (int i = 1; i < s.size(); ++i)
            best = max(best, i - start[i] + 1);

        return best;
    }
};



int
main(int argn, char** argv)
{
    Solution s;
}

