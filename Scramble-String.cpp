/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given a string s1, we may represent it as a binary tree by
partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t

To scramble the string, we may choose any non-leaf node and swap its
two children.

For example, if we choose the node "gr" and swap its two children, it
produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and
"at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a
scrambled string of s1.

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


using namespace std;


class Solution {
public:
    bool
    isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (s1.size() == 1) return s1 == s2;
        if (s1 == s2) return true;

        vector<int> counts(128, 0);
        for (size_t i = 0; i < s1.size(); ++i)
        {
            ++counts[s1[i]];
            --counts[s2[i]];
        }

        for (size_t i = 0; i < counts.size(); ++i)
            if (counts[i] != 0) return false;

        const int len = s1.size();
        for (int i = 1; i < len; ++i)
        {
            const int rem = len - i;
            if ((isScramble(s1.substr(0, i), s2.substr(0, i))
                 && isScramble(s1.substr(i, rem), s2.substr(i, rem)))
                ||
                (isScramble(s1.substr(0, i), s2.substr(rem, i))
                 && isScramble(s1.substr(i, rem), s2.substr(0, rem))))
                return true;
        }
        
        return false;

    }
};


int
main(int argn, char** argv)
{
    Solution s;
}

