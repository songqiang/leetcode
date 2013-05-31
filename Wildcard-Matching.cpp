/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:

bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "*") ? true
isMatch("aa", "a*") ? true
isMatch("ab", "?*") ? true
isMatch("aab", "c*a*b") ? false

*/


#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>

using namespace std;


class Solution {
public:

    void
    count_start_qm(const string &s, size_t &n_star, size_t &n_qm)
    {
        n_star = n_qm = 0;
        for (size_t i = 0; i < s.size(); ++i)
        {
            switch (s[i])
            {
            case '*': ++n_star; break;
            case '?': ++n_qm; break;
            } 
        }
    }

    bool
    isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        string str(s);
        string patt(p);
        
        vector<string> subs;
        vector<string> delims;

        size_t h = 0;
        size_t t = 0;
        while (h != string::npos && t != string::npos)
        {
            h = patt.find_first_not_of("*?", t);
            if (h == string::npos)
            {
                    delims.push_back(patt.substr(t));
                    break;
            }
            else
                delims.push_back(patt.substr(t, h - t));

            t = patt.find_first_of("*?", h);
            if (t == string::npos)
            {
                subs.push_back(patt.substr(h));
                break;
            }
            else
                subs.push_back(patt.substr(h, t - h));
        }

        size_t n_star, n_qm;
        count_start_qm(patt, n_star, n_qm);
        const size_t min_nchar = patt.size() - n_star;

        if (str.size() < min_nchar) return false;

        if (subs.empty()) 
        {
            if (n_qm == str.size())
                return true;
            else if (n_qm > str.size())
                return false;
            else if (n_qm < str.size())
                return n_star > 0;
        }

        vector<vector<size_t> >  pos(subs.size());
        size_t n_matched = 0;

        // deal with the first sub string;
        count_start_qm(delims.front(), n_star, n_qm);
        n_matched += n_qm;
        if (n_star == 0)
        {
            const size_t start = n_qm;
            const size_t p = str.find(subs.front(), start);
            if (p == start) 
                pos.front().push_back(p);
        }
        else
        {
            const size_t start = n_qm;
            const size_t max_start = str.size() - (min_nchar - n_qm);

            size_t p = start;
            while (p <= max_start && p != string::npos)
            {
                p = str.find(subs.front(), p);
                if (p <= max_start && p != string::npos)
                {
                    pos.front().push_back(p);
                    ++p;
                }
            }
        }

        // work on the remaing sub strings
        for (size_t i = 1; i < subs.size(); ++i)
        {
            if (pos[i - 1].empty()) return false;

            n_matched += subs[i-1].size();
            
            count_start_qm(delims[i], n_star, n_qm);
            n_matched += n_qm;

            if (n_star == 0)
            {
                for (size_t j = 0; j < pos[i-1].size(); ++j)
                {
                    const size_t start = pos[i-1][j] + subs[i-1].size() + n_qm;
                    const size_t p = str.find(subs[i], start);
                    if (p == start)  pos[i].push_back(p);
                }
            }
            else
            {
                const size_t start = pos[i-1].front() + subs[i-1].size() + n_qm;
                const size_t max_start = str.size() - (min_nchar - n_matched);

                size_t p = start;
                while (p <= max_start && p != string::npos)
                {
                    p = str.find(subs[i], p);
                    if (p <= max_start && p != string::npos)
                    {
                        pos[i].push_back(p);
                        ++p;
                    }
                }
            }
        }

        // deal with the last
        if (pos.back().empty()) return false;

        if (delims.size() == subs.size() + 1)
            count_start_qm(delims.back(), n_star, n_qm);
        else
            n_star = n_qm = 0;
        
        if (n_star == 0)
        {
            for (size_t j = 0; j < pos.back().size(); ++j)
                if (pos.back()[j] + subs.back().size() + n_qm == str.size())
                    return true;
        }
        else
        {
            for (size_t j = 0; j < pos.back().size(); ++j)
                if (pos.back()[j] + subs.back().size() + n_qm <= str.size())
                    return true;
        }

        return false;
    }
};

int
main(int argn, char** argv)
{
    Solution s;
    cout << s.isMatch("a", "a*") << endl;
    cout << s.isMatch("aa","aa") << endl;
    cout << s.isMatch("aaa", "aa") << endl;
    cout << s.isMatch("aa", "*") << endl;
    cout << s.isMatch("aa", "a*") << endl;
    cout << s.isMatch("ab", "?*") << endl;
    cout << s.isMatch("aab", "c*a*b") << endl;
}

// Some examples:
// isMatch("aa","a") ? false
// isMatch("aa","aa") ? true
// isMatch("aaa","aa") ? false
// isMatch("aa", "*") ? true
// isMatch("aa", "a*") ? true
// isMatch("ab", "?*") ? true
// isMatch("aab", "c*a*b") ? false



