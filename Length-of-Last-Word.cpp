/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

Given a string s consists of upper/lower-case alphabets and empty
space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space
characters only.

For example, 
Given s = "Hello World",
return 5.

*/

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        string str(s);
        size_t end = str.find_last_not_of(' ');
        if (e == string::npos) return 0;
        
        size_t start = str.find_last_of(' ', end);
        return start == string::npos ? end + 1 :  end - start;
    }
};

