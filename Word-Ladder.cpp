/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */

/*

Given two words (start and end), and a dictionary, find the length of
shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

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


using namespace std;

// class Solution {
// public:

//     bool
//     connected(const string &s1, const string& s2)
//     {
//         int n = 0;
//         for (size_t i = 0; i < s1.size(); ++i)
//         {
//             n += s1[i] != s2[i];
//             if (n > 1) return false;
//         }
        
//         return n == 1;
//     }
    

//     int
//     ladderLength(string start, string end, unordered_set<string> &dict) {
//         // Start typing your C/C++ solution below
//         // DO NOT write int main() function

//         unordered_map<string, int> md;
//         for (unordered_set<string>::iterator i = dict.begin(); i != dict.end(); ++i)
//             md[*i] = numeric_limits<int>::max();

//         md[start] = 0;
        
//         queue<string> q;
//         q.push(start);
//         while (!q.empty())
//         {
//             const string s = q.front();
//             q.pop();
            
//             const int d = md[s];
//             md.erase(s);
//             if (s == end) return d + 1;

//             for (unordered_map<string, int>::iterator i = md.begin(); i != md.end(); ++i)
//             {
//                 if (i->second == numeric_limits<int>::max()
//                     && connected(s, i->first))
//                 {
//                     i->second = d + 1;
//                     q.push(i->first);
//                 }
//             }
//         }

//         return 0;
//     }

// };

class Solution {
public:

    int
    ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function


        dict.insert(end);
        typedef unordered_set<string>::iterator setItr;

        unordered_map<string, unordered_map<int, vector<setItr> > > md;
        for (setItr i = dict.begin(); i != dict.end(); ++i)
            for (size_t j = 0; j < i->size(); ++j)
                md[i->substr(0, j) + i->substr(j + 1)][j].push_back(i);

        dict.insert(start);

        unordered_map<string, int> dist;
        for (setItr i = dict.begin(); i != dict.end(); ++i)
            dist[*i] = numeric_limits<int>::max();
        
        queue<setItr> q;
        q.push(dict.find(start));
        dist[start] = 1;

        while (!q.empty())
        {
            const setItr sitr = q.front();
            q.pop();
            
            if (*sitr == end) return dist[*sitr];

            for (int j = 0; j < sitr->size(); ++j)
            {
                const string strkey = sitr->substr(0, j) + sitr->substr(j + 1);
                const int idxkey = j;
                if (md.find(strkey) != md.end()
                    && md[strkey].find(idxkey) != md[strkey].end())
                {
                    vector<setItr> &itrs = md[strkey][idxkey];
                    while (!itrs.empty())
                    {
                        if (dist[*itrs.back()] == numeric_limits<int>::max())
                        {
                            q.push(itrs.back());
                            dist[*itrs.back()] = dist[*sitr] + 1;
                        }
                        itrs.pop_back();
                    }
                    md[strkey].erase(idxkey);
                    if (md[strkey].empty()) md.erase(strkey);
                }
            }
        }

        return 0;

    }
};




int
main(int argn, char** argv)
{
    Solution s;
}

