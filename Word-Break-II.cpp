/*
 * Song Qiang <keeyang@ustc.edu>
 */

/*

 Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"]. 

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
#include <functional>
#include <unordered_set>


using namespace std;

class Solution {
public:
    vector<string>
    wordBreak(string s, unordered_set<string> &dict) {

        if (s.empty()) return vector<string>(1, "");

        size_t max_word_len = 0;
        for (auto it = dict.begin(); it != dict.end(); ++it)
            max_word_len = max(max_word_len, it->size());
        
        vector<vector<string> > ss(s.size());
        
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (i >= max_word_len + 1)
                ss[i - max_word_len - 1].clear();

            for (size_t j = i; j > 0 && (j + max_word_len >= i + 1); --j)
                if (!ss[j - 1].empty())
                {
                    const string sub = s.substr(j, i - j + 1);
                    if (dict.find(sub) != dict.end())
                        for (size_t k = 0; k < ss[j - 1].size(); ++k)
                            ss[i].push_back(ss[j - 1][k] + " " + sub);
                }

            if (i + 1 <= max_word_len
                && dict.find(s.substr(0, i + 1)) != dict.end())
                ss[i].push_back(s.substr(0, i + 1));

        }

        return ss.back();
    }
};

int
main(int argn, char** argv)
{
    unordered_set<string> d;
    d.insert("cat");
    d.insert("cats");
    d.insert("and");
    d.insert("sand");
    d.insert("dog");
    
    Solution s;
    vector<string> r = s.wordBreak("catsanddog", d);
    for (size_t i = 0; i < r.size(); ++i)
        cout << r[i] << endl;
}



