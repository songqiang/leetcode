/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true


 */

#include <cmath>
#include <cstring>

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

    bool isMatch(const char *s, const char *p) {
        
        const int pn = strlen(p);
        const int sn = strlen(s);

        vector<int> prev;
        vector<int> curr;
        
        if (p[0] == '.' || p[0] == s[0]) 
            prev.push_back(0);
        
        if (pn > 2 && p[1] == '*' && (p[2] == '.' || p[2] == s[0]))
            prev.push_back(2);

        for (int i = 1; i < sn; ++i)
        {
             cout << s[i - 1] << ":\t";
             for_each(prev.begin(), prev.end(), [](int x) {cout << x << "\t";});
             cout << endl;

            if (prev.empty()) return false;
            
            for (int j = 0; j < prev.size(); ++j)
            {
                const int prev_id = prev[j];
                const int curr_id = prev_id + 1;

                if (p[prev_id] == '*' && (p[prev_id - 1] == '.' || s[i] == p[prev_id - 1])) curr.push_back(prev_id);

                    
                if (curr_id < pn) {
                    if (p[curr_id] == '*') {
                        if (p[prev_id] == '.' || s[i] == p[prev_id]) curr.push_back(curr_id);
                        if (curr_id + 1 < pn && (p[curr_id + 1] == '.' || s[i] == p[curr_id + 1])) curr.push_back(curr_id + 1);

                if (curr_id + 3 < pn && p[curr_id + 2] == '*' && (p[curr_id + 3] == '.' || p[curr_id + 3] == s[i])) 
                {
                    curr.push_back(curr_id + 3);
                }

                    } else if (p[curr_id] == '.' || p[curr_id] == s[i])
                        curr.push_back(curr_id);
                } 

                cout << curr_id << "\t" << p[curr_id] << p[curr_id + 1] << p[curr_id + 2] << endl;
                
                if (curr_id + 2 < pn && p[curr_id + 1] == '*' && (p[curr_id + 2] == '.' || p[curr_id + 2] == s[i])) 
                {
                    curr.push_back(curr_id + 2);
                }
            } 

            prev.assign(curr.begin(), curr.end());
            curr.clear();

        }

        cout << s[sn - 1] << ":\t";
        for_each(prev.begin(), prev.end(), [](int x) {cout << x << "\t";});
        cout << endl;
        return find(prev.begin(), prev.end(), pn - 1) != prev.end();
    }    

};


int
main(int argn, char** argv)
{
    Solution s;
    s.isMatch("aaa", "ab*a*c*a");
    
}

