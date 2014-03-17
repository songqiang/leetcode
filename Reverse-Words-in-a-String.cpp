/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.
Clarification:

    What constitutes a word?
    A sequence of non-space characters constitutes a word.
    Could the input string contain leading or trailing spaces?
    Yes. However, your reversed string should not contain leading or trailing spaces.
    How about multiple spaces between two words?
    Reduce them to a single space in the reversed string.

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
    void reverseWords(string &s) {
        
        int ws = 0;
        string r;
        int i = 0;
        while (i < s.size()) {
            int ws = i;
            while (ws < s.size() && isspace(s[ws])) ++ws;

            int we = ws == s.size() ? ws : (ws + 1);
            while(we < s.size() && !isspace(s[we])) ++we;
            
            if (we > ws) r = r.empty() ? s.substr(ws, we - ws) : s.substr(ws, we - ws) + " " + r;
            i = we + 1;
        }

        s = r;
    }
};

int
main(int argn, char** argv)
{
	Solution s;
}

