/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given an array of words and a length L, format the text such that each
line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many
words as you can in each line. Pad extra spaces ' ' when necessary so
that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as
possible. If the number of spaces on a line do not divide evenly
between words, the empty slots on the left will be assigned more
spaces than the slots on the right.

For the last line of text, it should be left justified and no extra
space is inserted between words.

For example,

words: ["This", "is", "an", "example", "of", "text", "justification."]

L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Note: Each word is guaranteed not to exceed L in length.

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

    string
    justity(vector<string> &w, const int s, const int L)
    {
        if (w.size() == 1) return w.front() + string(L - s, ' ');
        int n_gaps = w.size() - 1;
        int n_spaces = L - (s - n_gaps);
        
        int ng = n_spaces / n_gaps;
        int n_extra = n_spaces % n_gaps;

        string r(w.front());
        for (size_t i = 0; i < n_gaps; ++i)
        {
            r += string(ng + (i < n_extra), ' ') + w[i + 1];
        }
        
        return r;
    }

    string
    justity_last(vector<string> &w, const int L)
    {
        string s(w.front());
        for (size_t i = 1; i < w.size(); ++i)
            s += ' ' + w[i];
        return s + string(L - s.size(), ' ');
    }

    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (L == 0) return vector<string>(1, "");
        
        vector<string> r;

        int i = 0;
        vector<string> w;
        int s = 0;
        while (i < words.size())
            if (s + (w.size() > 0) + words[i].size() <= L)
            {
                s += words[i].size() + (w.size() > 0);
                w.push_back(words[i]);
                ++i;
            }
            else
            {
                r.push_back(justity(w, s, L));
                w.clear();
                s = 0;
            }

        if (w.size() != 0)
            r.push_back(justity_last(w, L));
        
        return r;
    }



};

int
main(int argn, char** argv)
{
    Solution s;
}

