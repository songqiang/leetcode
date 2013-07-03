/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

You are given a string, S, and a list of words, L, that are all of the
same length. Find all starting indices of substring(s) in S that is a
concatenation of each word in L exactly once and without any
intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

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
#include <unordered_map>


using namespace std;



// cannot pass the large test
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

    	const int wl = L.front().size();
		vector<int> r;
		unordered_map<string, int> wc, wcmax;
		for_each(L.begin(), L.end(), [&wc, &wcmax](const string &s){wc[s] = 0; wcmax[s] = 0;});
		for_each(L.begin(), L.end(), [&wcmax](const string &s){++wcmax[s];});

		for (int s = 0; s < wl; s++)
		{
			for_each(L.begin(), L.end(), [&wc](const string &s){wc[s] = 0;});
			int h =s,  t = s;
			int wn = 0;
			while (t <= int(S.size()) - wl)
			{
				const string w = S.substr(t, wl);
				if (wc.find(w) != wc.end())
				{
					wc[w] += 1;
					wn += wc[w] <= wcmax[w];
					if (wn == L.size())
					{
						r.push_back(h);
						--wn;
						--wc[S.substr(h, wl)];
						h += wl;
					}

					while (wc[w] > wcmax[w])
					{
						const string hw = S.substr(h, wl);
						wn -= wc[hw] <= wcmax[hw]  ;
						--wc[hw];
						h += wl;
					}
                    t += wl;  
				}
				else
				{
					for_each(L.begin(), L.end(), [&wc](const string &s){wc[s] = 0;});
					wn = 0;
					h  = t = t + wl;
				}
			}
		}

		return r;
    }
};

class MySolution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

    	const int wl = L.front().size();
        const int sl = S.size();
        
		vector<int> r;
		unordered_map<string, int> wc, wcmax;
		for_each(L.begin(), L.end(),
                 [&wc, &wcmax](const string &s){wc[s] = 0; wcmax[s] = 0;});
		for_each(L.begin(), L.end(),
                 [&wcmax](const string &s){++wcmax[s];});

		for (int s = 0; s < wl; s++)
		{
			for_each(L.begin(), L.end(), [&wc](const string &s){wc[s] = 0;});
			int h = s,  t = s;
            int wn = 0;

            while (t < sl)
            {
                if ((t - h) / wl == L.size())
                {
                    const string hw = S.substr(h, wl);
                    if (wc.find(hw) != wc.end())
                    {
                        wn -= wc[hw] <= wcmax[hw];
                        --wc[hw];
                    }
                    h += wl;
                }
                
                while ((t - h) / wl < L.size() && t < sl)
                {
                    const string tw = S.substr(t, wl);
                    if (wc.find(tw) != wc.end())
                    {
                        ++wc[tw];
                        wn += wc[tw] <= wcmax[tw];
                    }
                    t += wl;
                }

                if (wn == L.size()) r.push_back(h);
            }
		}

		return r;
    }
};


int
main(int argn, char** argv)
{
    string S = "sheateateseatea";
    vector<string> L({"sea","tea","ate"});
	MySolution s;
    vector<int> r(s.findSubstring(S, L));
}

