/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.


*/

// time O(n^2): mostly for moving data

class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (n == 0 || k == 0) return "";
        
        vector<int> factorials(n, 1);
        for (int i = 1; i < n; ++i)
            factorials[i] = factorials[i-1] * i;

        vector<int> idx(n, 0);
        for (int i = 0; i < n; ++i)
        {
            const int m = n - 1 - i;
            int reminder = k % factorials[m];
            int quotient = k / factorials[m];

            idx[i] = quotient - (reminder == 0);
            k = reminder == 0 ? factorials[m] : reminder;
        }

        vector<int> numbers(n);
        for (size_t i = 0; i < n; ++i)
            numbers[i] = i + 1;

        for (size_t i = 0; i < n; ++i)
        {
            int num = numbers[i + idx[i]];
            for (int j = i + idx[i]; j > i; --j)
                numbers[j] = numbers[j - 1];
            numbers[i] = num;
        }

        // output 
        stringstream result;
        for (size_t i = 0; i < n; ++i)
            result << numbers[i];
        return result.str().c_str();
    }
};




