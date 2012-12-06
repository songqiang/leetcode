/*
 * Song Qiang <qiang.song@usc.edu> 2012
 *
 */

/*


 */

/*
Decode ways

A message containing letters from A-Z is being encoded to numbers
using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given an encoded message containing digits, determine the total number
of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

*/

class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        const size_t n = s.size();
        if (n == 0) return 0;

        vector<size_t> counts(n, 0);

        // last digits
        counts[n - 1] = s[n - 1] == '0' ? 0 : 1;
        if (s.size() == 1) return counts.front();
        
        // last two digits
        if (s[n - 2] == '0')
            counts[n - 2] = 0;
        else
        {
            counts[n - 2] += counts[n -1];
            if (s[n - 2] == '1' || (s[n - 2] == '2' && s[n - 1] <= '6'))
                counts[n - 2] += 1;
        }

        // iterate for all other digits
        for (int i = n - 3; i >= 0 ; --i)
        {
            if (s[i] == '0')
                counts[i] = 0;
            else
            {
                counts[i] += counts[i + 1];
                if (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
                    counts[i] += counts[i + 2];
            }
        }

        return counts.front();
    }
};
