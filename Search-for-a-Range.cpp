/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

Given a sorted array of integers, find the starting and ending
position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

*/

class Solution {
public:

    int
    first_greater(int A[], int n, int target)
    {
        int h = 0;
        int t = n;
        while (h < t)
        {
            int m = (h + t) / 2;
            if (A[m] > target)
                t = m - 1;
            else if (A[m] <= target)
                h = m + 1;
        }
        return  h < n && A[h] == target ? h + 1 : h;
    }

    int
    last_smaller(int A[], int n, int target)
    {
        int h = 0;
        int t = n;
        while (h < t)
        {
            int m = (h + t) / 2;
            if (A[m] >= target)
                t = m - 1;
            else if (A[m] < target)
                h = m + 1;
        }
        return A[h] == target ? h - 1 : h;
    }
    
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        const int s = last_smaller(A, n, target);
        const int e = first_greater(A, n, target);

        vector<int> r;
        if (s + 1 > e - 1)
        {
            r.push_back(-1);
            r.push_back(-1);
        }
        else
        {
            r.push_back(s + 1);
            r.push_back(e - 1);
        }

        return r;
    }

    vector<int> searchRange_STL(int A[], int n, int target) {
        
        auto l = std::lower_bound(A, A + n, target);
        auto u = std::upper_bound(A, A + n, target);
        vector<int> r(2, -1);
        if (l != u)
        {
            r.front() = l - A;
            r.back() = u - A - 1;
        }
        return r;
        
    }

};
