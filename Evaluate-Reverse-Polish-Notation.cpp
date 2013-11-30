/*
 * Song Qiang <keeyang@ustc.edu>
 */

/*

Evaluate Reverse Polish Notation

Evaluate the value of an arithmetic expression in Reverse Polish
Notation.

Valid operators are +, -, *, /. Each operand may be an integer or
another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

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
#include <stack>


using namespace std;

class Solution {
public:

    inline bool
    is_operator(const string &s)
    {
        return s == "+" || s == "-" || s == "/" || s ==  "*";
    }

    int
    evalRPN(vector<string> &tokens) {

        stack<int> numbers;
        
        for (size_t i = 0; i < tokens.size(); ++i)
        {
            if (is_operator(tokens[i]))
            {
                const int b = numbers.top();
                numbers.pop();
                const int a = numbers.top();
                numbers.pop();

                numbers.push(0);

                switch (tokens[i][0])
                {
                case '+': numbers.top() = a + b; break;
                case '-': numbers.top() = a - b; break;
                case '*': numbers.top() = a * b; break;
                case '/': numbers.top() = a / b; break;
                } 
            }
            else
            {
                numbers.push(atoi(tokens[i].c_str()));
            }
        }
        
        return numbers.top();
    }
};

int
main(int argn, char** argv)
{
    Solution s;
}
