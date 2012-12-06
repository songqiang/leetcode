/*
 * Song Qiang <qiang.song@usc.edu> 2012
 *
 */

/*


 */

/*

Count and Say

The count-and-say sequence is the sequence of integers beginning as
follows: 1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

*/

class Solution {
public:

    string
    countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (n <= 0) return "";

        string curr, next;
        curr = string("1");
        
        for (size_t i = 0; i < n - 1; ++i)
        {
            size_t p = 0;
            while (p != string::npos)
            {
                const size_t next_p = curr.find_first_not_of(curr[p], p);
                next += toa((next_p == string::npos ? curr.size() : next_p) - p);
                next += curr.substr(p, 1);
                p = next_p;
            }

            curr = next;
            next = "";
        }
        return curr;
    }

    string
    toa(const size_t n)
    {
        std::ostringstream oss;
        oss << n;
        return oss.str();
    }

};
