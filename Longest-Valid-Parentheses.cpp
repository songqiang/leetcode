/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

  Given a string containing just the characters '(' and ')', find the
  length of the longest valid (well-formed) parentheses substring.

  For "(()", the longest valid parentheses substring is "()", which has
  length = 2.

  Another example is ")()())", where the longest valid parentheses
  substring is "()()", which has length = 4.

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
	int longestValidParentheses(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
        
		if (s.empty()) return 0;

		vector<int> dangle(s.size(),-1);
		vector<int> matched(s.size(), -1);

		for (size_t i = 1; i < s.size(); ++i)
		{
			dangle[i] = s[i - 1] == '(' ? (i - 1) : dangle[i - 1];
			if (s[i] == ')' && dangle[i] != -1)
			{
				matched[i] = dangle[i];
				dangle[i] = dangle[matched[i]];
			}
		}

		int best = 0;
		int len = 0;
		int i = s.size() - 1;
		while (i >= 0)
		{
			if (matched[i] != -1)
			{
				len += i - matched[i] + 1;
				i = matched[i] - 1;
			}
			else
			{
				best = max(best, len);
				len  = 0;
				--i;
			}
		}
		best = max(best, len);

		return best;
	}
};


int
main(int argn, char** argv)
{
	Solution s;
}

