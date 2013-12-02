/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

There are two sorted arrays A and B of size m and n respectively. Find
the median of the two sorted arrays. The overall run time complexity
should be O(log (m+n)).

*/

#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <iterator>


using namespace std;


// find the Kth element
class Solution {
public:

    // find kth number

    double
    findKth(int A[], int m, int B[], int n, int k)
    {
        if (m > n)
            return findKth(B, n, A, m, k);
        if (m == 0)
            return B[k - 1];
        if (k == 1)
            return min(A[0], B[0]);
        
        int pa = min(k / 2, m);
        int pb = k - pa;
        if (A[pa - 1] < B[pb - 1])
            return findKth(A + pa, m - pa, B, n, k - pa);
        else if (A[pa - 1] > B[pb - 1])
            return findKth(A, m, B + pb, n - pb, k - pb);
        else 
            return A[pa - 1];
    } 

    double
    findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        return (m + n) % 2 == 1 ?
            findKth(A, m, B, n, (m + n) / 2 + 1)
            : (findKth(A, m, B, n, (m + n) / 2) + findKth(A, m, B, n, (m + n) / 2 + 1)) / 2;
        
    }
};

int
main(int argn, char** argv)
{
    int A[] = {2};
    int B[] = {1, 3};
    Solution s;

    cout << s.findMedianSortedArrays(A, 1, B, 2) << endl;
}

// [1,2,5], [3,4,6,7,8]
