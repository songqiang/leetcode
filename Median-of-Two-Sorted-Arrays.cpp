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

    double
    findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const int k = (m + n) / 2;

        
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
