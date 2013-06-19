/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1
and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

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

// naive solution. time runout for large test data
class SolutionNaive {
public:

    bool isInterleave(const string &s1, const int i1,
                      const string &s2, const int i2,
                      const string &s3, const int i3)
    {
        if (i1 == s1.size())
            return s2.substr(i2) == s3.substr(i3);
        if (i2 == s2.size())
            return s1.substr(i1) == s3.substr(i3);
        if (i3 == s3.size())
            return i1 == s1.size() && i2 == s2.size();
            
        return (s1[i1] == s3[i3] && isInterleave(s1, i1 + 1, s2, i2, s3, i3 + 1))
            || (s2[i2] == s3[i3] && isInterleave(s1, i1, s2, i2 + 1, s3, i3 + 1));
    }

    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    

        return isInterleave(s1, 0, s2, 0, s3, 0);
    }

};

class Solution {
public:

    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    

        if (s1.size() + s2.size() != s3.size()) return false;
        if (s1.empty()) return s2 == s3;
        if (s2.empty()) return s1 == s3;

        vector<set<pair<int, int> > > pos(s3.size());

        if (s1[0] == s3[0]) pos[0].insert(make_pair(0, -1));
        if (s2[0] == s3[0]) pos[0].insert(make_pair(-1, 0));
        if (pos[0].empty()) return false;

        for (size_t i = 1; i < s3.size(); ++i)
        {
            typedef set<pair<int, int> >::iterator ItrT;
            for (ItrT it = pos[i - 1].begin(); it !=  pos[i - 1].end(); ++it)
            {
                const int p1 = it->first + 1;
                if (p1 < s1.size() && s1[p1] == s3[i])
                    pos[i].insert(make_pair(p1, it->second));

                const int p2 = it->second + 1;
                if (p2 < s2.size() && s2[p2] == s3[i])
                    pos[i].insert(make_pair(it->first, p2));
            }

            pos[i - 1].clear();
            if (pos[i].empty()) return false;
        }


        return true;
    }
};


int
main(int argn, char** argv)
{
    Solution s;
}

// "a", "b", "ab"

// "ab", "bc", "bbac"

// "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa", 
// "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab",
// "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab"

