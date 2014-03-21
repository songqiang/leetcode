/*

Roman to integer

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

 */

class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> d{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        
        int n = 0;
        for (int i = 0; i < s.size(); ++i) 
            n += (i + 1 < s.size() && d[s[i]] < d[s[i + 1]]) ? -d[s[i]] : d[s[i]];

        return n;

    }
};



