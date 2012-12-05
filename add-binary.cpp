/*
 * add binary
 * Song Qiang <qiang.song@usc.edu> 2012-10-10
 *
 * test passed
 */

class Solution 
{
public:
    string AddBinary(const string &a, const string &b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        string s1(a), s2(b);
        std::reverse(s1.begin(), s1.end());
        std::reverse(s2.begin(), s2.end());

        char t = '0';
        string r;
        for (size_t i = 0; i < std::min(s1.size(), s2.size()); ++i)
        {
            assert(s1[i] == '0' || s1[i] == '1');
            assert(s2[i] == '0' || s2[i] == '1');

            const size_t sum = s1[i] - 48 + s2[i] - 48 + t - 48;
            switch (sum)
            {
            case 0:
                r += "0";
                t = '0';
                break;
            case 1:
                r += "1";
                t = '0';
                break;
            case 2:
                r += "0";
                t = '1';
                break;
            case 3:
                r += "1";
                t = '1';
                break;
            } 
        }

        for (size_t i = std::min(s1.size(), s2.size()); i < s1.size(); ++i)
        {
            assert(s1[i] == '0' || s1[i] == '1');

            const size_t sum = s1[i] - 48 + t - 48;
            switch (sum)
            {
            case 0:
                r += "0";
                t = '0';
                break;
            case 1:
                r += "1";
                t = '0';
                break;
            case 2:
                r += "0";
                t = '1';
                break;
            } 
        }

        for (size_t i = std::min(s1.size(), s2.size()); i < s2.size(); ++i)
        {
            assert(s2[i] == '0' || s2[i] == '1');

            const size_t sum = s2[i] - 48 + t - 48;
            switch (sum)
            {
            case 0:
                r += "0";
                t = '0';
                break;
            case 1:
                r += "1";
                t = '0';
                break;
            case 2:
                r += "0";
                t = '1';
                break;
            } 
        }

        r += t == '1' ? "1" : "";

        std::reverse(r.begin(), r.end());
        return r;
    }
    
};
