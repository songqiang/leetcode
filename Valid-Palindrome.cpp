/*
 * Song Qiang <qiang.song@usc.edu>
 *
 */

/*

Valid PalindromeJan 13

Given a string, determine if it is a palindrome, considering only
alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:

Have you consider that the string might be empty? This is a good
question to ask during an interview.

For the purpose of this problem, we define empty string as valid
palindrome.

 */

class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        for (int i = 0; i < s.size(); ++i) 
            s[i] = toupper(s[i]);

        int j = 0;
        
        for (int i = 0; i < s.size(); ++i)
            if (isalnum(s[i]))
                s[j++] = s[i];

        int i = 0;
        while (i < j - 1 - i) 
        {
            if (s[i] != s[j - 1 - i]) return false;
            ++i;
        }
        
        return true;
    }
};
