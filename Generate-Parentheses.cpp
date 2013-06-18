/*
 * Song Qiang <qiang.song@usc.edu> 2012
 */


/*

Generate Parentheses 

Given n pairs of parentheses, write a function to generate all
combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

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

    vector<string>
    generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<vector<string> > results(n + 1);
        results[0] = vector<string>(1, "");
        results[1] = vector<string>(1, "()");

        for (int i = 2; i < n + 1; ++i)
        {
            for (int j = 1; j < 2 * i; j += 2)
            {
                const int bef = (j - 1) / 2;
                const int af = (i * 2 - j - 1) / 2;
                for (int b = 0; b < results[bef].size(); ++b)
                    for (int a = 0; a < results[af].size(); ++a)
                        results[i].push_back("(" + results[bef][b] + ")"
                                             + results[af][a]);
            }
        }

        return results[n];


    }
};


int
main(int argn, char** argv)
{
    Solution s;
}
