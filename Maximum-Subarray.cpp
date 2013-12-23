/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

Find the contiguous subarray within an array (containing at least one
number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4], the contiguous
subarray [4,−1,2,1] has the largest sum = 6.

More practice: If you have figured out the O(n) solution, try coding
another solution using the divide and conquer approach, which is more
subtle.  » Solve this problem

*/

class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int best = A[0];
        int prev = A[0];
        
        for (int i = 1; i < n; ++i)
        {
            prev = max(prev, 0) + A[i];
            best = max(best, prev);
        }
        
        return best;


        // if (n == 0) return 0;
        // vector<int> result(n);
        
        // result[0] = A[0];
        // for (size_t i = 1; i < n; ++i)
        //     result[i] = result[i - 1] > 0 ? result[i - 1] + A[i] : A[i];
        
        // return *max_element(result.begin(), result.end());

    }
};


