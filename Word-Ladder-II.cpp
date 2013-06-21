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
#include <iterator>

using namespace std;

class Solution {
public:

    typedef unordered_set<string>::iterator setItr;

    vector<vector<string> >
    back_track(const setItr itr,
               unordered_map<string, vector<setItr> > &prevs)
    {
        vector<vector<string> > results;
        for (size_t i = 0; i < prevs[*itr].size(); ++i)
        {
            vector<vector<string> > tmp(back_track(prevs[*itr][i], prevs));
            copy(tmp.begin(), tmp.end(), back_inserter(results)); 
        }

        for (size_t i = 0; i < results.size(); ++i)
            results[i].push_back(*itr);

        if (results.empty()) results.push_back(vector<string>(1, *itr));
        
        return results;
    }


    vector<vector<string> >
    findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function


        dict.insert(start);
        dict.insert(end);

        unordered_map<string, unordered_map<int, vector<setItr> > > md;
        for (setItr i = dict.begin(); i != dict.end(); ++i)
            for (size_t j = 0; j < i->size(); ++j)
                md[i->substr(0, j) + i->substr(j + 1)][j].push_back(i);


        unordered_map<string, int> dist;
        unordered_map<string, vector<setItr> > prevs;
        for (setItr i = dict.begin(); i != dict.end(); ++i)
        {
            dist[*i] = numeric_limits<int>::max();
            prevs[*i] = vector<setItr>();
        }

        vector<vector<string> >  results;

        queue<setItr> q;
        q.push(dict.find(start));
        dist[start] = 1;
        
        while (!q.empty())
        {
            const setItr sitr = q.front();
            q.pop();

//            cerr << "[" << *sitr << "] pushed:";

            if (*sitr == end)
                return back_track(sitr, prevs);

            for (int j = 0; j < sitr->size(); ++j)
            {
                const string strkey = sitr->substr(0, j) + sitr->substr(j + 1);
                const int idxkey = j;
                if (md.find(strkey) != md.end()
                    && md[strkey].find(idxkey) != md[strkey].end())
                {
                    vector<setItr> &itrs = md[strkey][idxkey];
                    int ii = 0;
                    for (size_t i = 0; i < itrs.size(); ++i)
                        if (dist[*itrs[i]] > dist[*sitr])
                            itrs[ii++] = itrs[i];
                    itrs.erase(itrs.begin() + ii, itrs.end());

                    for (size_t i = 0; i < itrs.size(); ++i)
                        if (dist[*itrs[i]] == numeric_limits<int>::max())
                        {
                            q.push(itrs[i]);
                            dist[*itrs[i]] = dist[*sitr] + 1;
                            prevs[*itrs[i]].push_back(sitr);
//                            cerr << *itrs[i] << "\t"; //////////////
                        }
                        else if (dist[*sitr] + 1 == dist[*itrs[i]])
                        {
                            prevs[*itrs[i]].push_back(sitr);
                        }
                    if (itrs.empty()) md[strkey].erase(idxkey);
                }
                if (md[strkey].empty()) md.erase(strkey);
            }

//            cerr << endl; //////////////
        }
        
        return results;
    }

};


int
main(int argn, char** argv)
{
    string start = "qa";
    string end = "sq";
    unordered_set<string> dict({"qa", "pa", "pi", "si", "sq"});

    Solution s;
    vector<vector<string> > results(s.findLadders(start, end, dict));

    cout << endl;
    for (size_t i = 0; i < results.size(); ++i)
    {
        copy(results[i].begin(), results[i].end(), ostream_iterator<string>(cout, ", "));
        cout << endl;
    }
}



