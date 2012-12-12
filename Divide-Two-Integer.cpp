
/*
 * Song Qiang <qiang.song@usc.edu> 2012
 */


/*

Divide Two Integers

Divide two integers without using multiplication, division and mod
operator.

 */

                   
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (dividend == 0) return 0;
        
        int sgn = ((dividend > 0 && divisor < 0)
                    || (dividend < 0 && divisor > 0 )) ? -1 : 1;

        double fdividend = fabs(dividend);
        double fdivisor = fabs(divisor);

        int t = static_cast<int>(exp(log(fdividend) - log(fdivisor)));           
                   
        return sgn == 1 ? r : -r;
    }
};

