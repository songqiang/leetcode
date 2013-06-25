/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given a string s, partition s such that every substring of the
partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]

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
    
    vector<vector<string> >
    getPartition(const string &s, const vector<vector<int> > &palin, const int id)
    {
        vector<vector<string> > results;
        for (int i = 0; i < palin[id].size(); ++i)
        {
            string ss(s.substr(palin[id][i], id + 1 - palin[id][i]));

            vector<vector<string> > r;
            if (palin[id][i] - 1 >= 0)
                r = getPartition(s, palin, palin[id][i] - 1);
            for_each(r.begin(), r.end(),
                     [&ss](vector<string> &v) {v.push_back(ss);} );
            if (r.empty())
                r.push_back(vector<string>(1, ss));
            
            copy(r.begin(), r.end(), back_inserter(results));
        }
        
        return results;
    }

    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (s.empty())
        {
            vector<vector<string> > r;
            r.push_back(vector<string>(1, ""));
            return r;
        }

        vector<vector<int> > palin(s.size());

        palin.front().push_back(0);
        
        for (int i = 1; i < s.size(); ++i)
        {
            palin[i].push_back(i);
            if (s[i] == s[i - 1])
                palin[i].push_back(i - 1);

            for (int j = 0; j < palin[i - 1].size(); ++j)
                if (palin[i - 1][j] - 1 >= 0
                    && s[palin[i - 1][j] - 1] == s[i])
                    palin[i].push_back(palin[i - 1][j] - 1);
        }

        return getPartition(s, palin, s.size() - 1);
    }
};


int
main(int argn, char** argv)
{
    Solution s;
}

