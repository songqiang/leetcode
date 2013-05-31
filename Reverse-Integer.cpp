/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

  Reverse digits of an integer.
  
  Example1: x = 123, return 321
  Example2: x = -123, return -321
        
*/


class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (x == 0) return 0;
        if (x < 0) return -reverse(-x);

        int n_digits = static_cast<int>(floor(log(x) / log(10)) + 1);
        int s = 0;
        for (size_t i = 0; i < n_digits; ++i)
        {
            int r = x % 10;
            s *= 10;
            s += r;
            x = x / 10;
        }

        return s;
    }
    
};

