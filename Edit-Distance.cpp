/*
 * Song Qiang <qiang.song@usc.edu> 2012
 */


/*

Edit Distance

Given two words word1 and word2, find the minimum number of steps
required to convert word1 to word2. (each operation is counted as 1
step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

 */

#include <vector>
#include <iostream>
#include <string>
#include <limits>
#include <iterator>


using namespace std;


// dynamic programming
class Solution {
public:

    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (word2.empty()) return word1.size();
        if (word1.empty()) return word2.size();
        
        vector<vector<int> > d(word2.size(),
                               vector<int>(word1.size(),
                                           numeric_limits<int>::max()));

        vector<vector<int> > dexcl(word2.size(),
                               vector<int>(word1.size(),
                                           numeric_limits<int>::max()));

        for (int i1 = 0; i1 < word1.size(); ++i1)
        {
            d[0][i1] = (word2[0] != word1[i1]) + i1;
            dexcl[0][i1] = min(d[0][i1],
                               i1 > 0 ? (1 + dexcl[0][i1 - 1]) : numeric_limits<int>::max());
        }
        
        for (int i2 = 1; i2 < word2.size(); ++i2)
            for (int i1 = 0; i1 < word1.size(); ++i1)
            {
                const int mismatch = word1[i1] != word2[i2];
                if (i1 == 0)
                    d[i2][i1] = mismatch + i2;
                else
                    d[i2][i1] = mismatch + dexcl[i2 - 1][i1 - 1];

                dexcl[i2][i1] = min(d[i2][i1],
                                    min(i2 > 0 ? (1 + dexcl[i2 - 1][i1]) : numeric_limits<int>::max(),
                                        i1 > 0 ? (1 + dexcl[i2][i1 - 1]) : numeric_limits<int>::max()));
            }

        int best = numeric_limits<int>::max();
        for (int i1 = 0; i1 < word1.size(); ++i1)
            best = min(best,
                       int(d[word2.size() - 1][i1] + word1.size() - i1 - 1));

        for (int i2 = 0; i2 < word2.size(); ++i2)
            best = min(best,
                       int(d[i2][word1.size() - 1] + word2.size() - i2 - 1));
        return best;
    }
};

                   

int
main(int argc, char *argv[])
{
    Solution r;
    cout << r.minDistance(argv[1], argv[2]) << endl;
    return 0;
}


// "pla   sma", 
// "altruism"
