/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given a digit string, return all possible letter combinations that the
number could represent.

A mapping of digit to letters (just like on the telephone buttons) is
given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

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
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (digits.empty()) return vector<string>(1, "");
        
        static const char* letters[] =
            {" \0", "\0", "abc\0", "def\0", "ghi\0", "jkl\0",
             "mno\0", "pqrs\0", "tuv\0", "wxyz\0"};

        const int d = digits[0] - 48;
        vector<string> r;
        const char* p = letters[d];

        if (digits.size() == 1)
        {
            while (*p != '\0')
            {
                r.push_back(string(p, 1));
                ++p;
            }
            return r;
        }

        vector<string> rr(letterCombinations(digits.substr(1)));
        while (*p != '\0')
        {
            const string s(p, 1); 
            for (size_t i = 0; i < rr.size(); ++i)
                r.push_back(s + rr[i]);
            ++p;
        }

        return r;

    }
};


class Solution2 {
public:

    void
    get_chars(const string &digits,  const vector<string>& chars, int id, string &s, vector<string> &r ) {
        if (id == digits.size()) {r.push_back(s); return;}

        if (digits[id] == '0' || digits[id] == '1') {
            get_chars(digits, chars, id + 1, s, r);
            return;
        }    
        
        s.push_back('-');
        for (char c : chars[digits[id] - 48]) {
            s.back() = c;
            get_chars(digits, chars, id + 1, s, r);
        }
        s.pop_back();        
    }
    

    vector<string> letterCombinations(string digits) {
        
        vector<string> chars{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> r;
        string s;
        get_chars(digits, chars, 0, s, r);
        return r;
    }
};


int
main(int argn, char** argv)
{
    Solution s;
    
}

