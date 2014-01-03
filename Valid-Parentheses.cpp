/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given a string containing just the characters '(', ')', '{', '}', '['
and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are
all valid but "(]" and "([)]" are not.

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

    bool isValid(string s) {
        
        stack<char> st;
        for (size_t i = 0; i < s.size(); ++i)
            switch (s[i])
            {
                case ')':
                    if (st.empty()  || st.top() != '(')
                        return false;
                    st.pop();
                    break;
                case ']':
                    if (st.empty()  || st.top() != '[')
                        return false;
                    st.pop();
                    break;
                case '}':
                    if (st.empty()  || st.top() != '{')
                        return false;
                    st.pop();
                    break;
                default:
                    st.push(s[i]);
            }
        return st.empty();      

    }

    bool isValid_bad_solution(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (s.empty()) return true;
        if (s[0] == ')' || s[0] == ']' || s[0] == '}') return false;

        vector<int> pp(s.size(), s[0] == '(' ? 0 : -1);
        vector<int> sp(s.size(), s[0] == '[' ? 0 : -1);
        vector<int> cp(s.size(), s[0] == '{' ? 0 : -1);
        
        for (int i = 1; i < s.size(); ++i)
        {
            switch (s[i])
            {
            case '(':
                pp[i] = i;
                sp[i] = sp[i - 1];
                cp[i] = cp[i - 1];
                break;
            case ')':
                if (pp[i - 1] == -1 || pp[i - 1] < sp[i - 1]
                    || pp[i - 1] < cp[i - 1])
                    return false;
                pp[i] = pp[i - 1] == 0 ? -1 : pp[pp[i - 1] - 1];
                sp[i] = sp[i - 1];
                cp[i] = cp[i - 1];
                break;
            case '[':
                pp[i] = pp[i - 1];
                sp[i] = i;
                cp[i] = cp[i - 1];
                break;
            case ']':
                if (sp[i - 1] == -1 || sp[i - 1] < pp[i - 1]
                    || sp[i - 1] < cp[i - 1])
                    return false;
                pp[i] = pp[i - 1];
                sp[i] = sp[i - 1] == 0 ? -1 : sp[sp[i - 1] - 1];
                cp[i] = cp[i - 1];
                break;
            case '{':
                pp[i] = pp[i - 1];
                sp[i] = sp[i - 1];
                cp[i] = i;
                break;
            case '}':
                if (cp[i - 1] == -1 || cp[i - 1] < pp[i - 1]
                    || cp[i - 1] < sp[i - 1])
                    return false;
                pp[i] = pp[i - 1];
                sp[i] = sp[i - 1];
                cp[i] = cp[i - 1] == 0 ? -1 : cp[cp[i - 1] - 1];
                break;
            } 
        }

        return pp.back() == -1 && sp.back() == -1 && cp.back() == -1;
    }
};


int
main(int argn, char** argv)
{
    Solution s;
    cout << s.isValid("]") << endl;
}

