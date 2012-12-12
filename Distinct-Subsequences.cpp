/*
 * Song Qiang <qiang.song@usc.edu> 2012
 */


/*

Distinct Subsequences

Given a string S and a string T, count the number of distinct
subsequences of T in S.

A subsequence of a string is a new string which is formed from the
original string by deleting some (can be none) of the characters
without disturbing the relative positions of the remaining
characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is
not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

 */

class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        const size_t ns = S.size();
        const size_t nt = T.size();
        
        vector<size_t> counts(nt, 0), curr_counts(nt, 0);

        for (int i =  S.size() - 1; i >= 0; --i)
        {
            for (size_t j = 0; j < nt; ++j)
            {
                curr_counts[j] += counts[j];
                if (S[i] == T[j])
                    curr_counts[j] += (j == nt - 1) ? 1 : counts[j + 1];
            }

            std::copy(curr_counts.begin(), curr_counts.end(), counts.begin()); 
            std::fill(curr_counts.begin(), curr_counts.end(), 0); 
        }
        
        return counts[0];
    }
};


