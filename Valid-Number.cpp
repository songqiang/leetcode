/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You
should gather all requirements up front before implementing one.

 */

#include <cmath>
#include <cstdlib>


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
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (s == NULL) return false;
        
        int n_dot = 0;
        int n_e = 0;
        int n_digits = 0;
        int n_blank = 0;

        const char* p = s;
        while (*p != '\0' && (*p == ' ' || *p == '\t')) ++p;
        if (*p != '\0' && (*p == '+' || *p == '-')) ++p;

        char prev = 0;
        while (*p != '\0')
        {
            switch (*p)
            {
            case '+':
            case '-':
                if (prev != 'e' && prev != 'E')
                    return false;
                break;
            case 'e':
            case 'E': 
                if (n_digits == 0 || n_e > 0 || n_blank > 0) return false;
                ++n_e;
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                if (n_blank > 0) return false;
                ++n_digits;
                break;
            case '.':
                if (n_dot > 0 || n_e > 0 || n_blank > 0) return false;
                ++n_dot;
                break;
            case ' ':
            case '\t':
                if (prev == 'e' || prev == 'E'
                    || prev == '+' || prev == '-') return false;
                ++n_blank;
                break;
            default:
                return false;
            } 

            prev = *p;
            ++p;
        }

        return prev != 'e' && prev != 'E'
            && prev != '+' && prev != '-' && n_digits > 0;
    }
};



int
main(int argn, char** argv)
{
    Solution s ;
    cout << s.isNumber("0") << endl;
}

