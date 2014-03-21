/*



Integer to Roman
Total Accepted: 6052 Total Submissions: 18774

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

 */

class Solution {
public:
    string intToRoman(int num) {
        
        vector<int> vals{1, 5, 10, 50, 100, 500, 1000};
        vector<string> symbols{"I", "V", "X", "L", "C", "D", "M"};
        
        string s;
        for (int i = vals.size() - 1; i >= 0 && num > 0; --i)
        {
            if (i % 2 == 1 && i >= 1) {
                int n  = num / vals[i - 1];
                if (n == 9) {
                    s += symbols[i - 1] + symbols[i + 1];
                    num -= n * vals[i - 1];
                }
            }
                
            int n = num / vals[i];
            num %= vals[i];
            
            if (n == 4) 
                s+= symbols[i] + symbols[i + 1];
            else
                for (int j = 0; j < n; ++j) s += symbols[i];
        }

        return s;

    }
};


