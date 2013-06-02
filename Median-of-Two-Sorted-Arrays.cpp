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


using namespace std;


class Solution {
public:

    double findMedian(int A[], int h, int t)
    {
        if ((t - h) % 2 == 1) 
            return A[(h + t - 1) / 2];
        else
            return (A[(h + t - 1) / 2] + A[(h + t - 1) / 2 + 1]) / 2.0;
    }
    
    double
    findMedian(int A[], int ha, int ta, int B[], int hb, int tb)
    {
/////
        cerr << "check 1: "<< ha << "," << ta << "\t" << hb << "," << tb << endl;
/////
        const int n_a = ta - ha;
        const int n_b = tb - hb;
        if (n_a > n_b)
            return findMedian(B, hb, tb, A, ha, ta);
        
        if (ha == ta) 
            return findMedian(B, hb, tb);

        if (ta - ha == 1)
        {
            int lb = lower_bound(B + hb, B + tb, A[ha]) - B;
            if ((tb - hb) % 2 == 1)
            {
                int mid = (hb + tb - 1) / 2;
                if (lb == mid)
                    return (A[ha] + B[mid]) / 2.0;
                else if (lb < mid)
                    return mid - 1 >= hb ?
                        (max(B[mid - 1], A[ha]) + B[mid]) / 2.0
                        : (A[ha] + B[mid]) / 2.0;
                else
                    return mid + 1 < tb ?
                        (B[mid] + min(B[mid + 1], A[ha])) / 2.0
                        : (A[ha] + B[mid]) / 2.0;
            }
            else
            {
                int mid = (hb + tb - 1) / 2;
                if (lb <= mid)
                    return max(A[ha], B[mid]);
                else
                    return min(A[ha], B[mid + 1]);
            }
        }

        if (tb - hb <= 3)
        {
            int tv[ta - ha + tb - hb];
            int i = ha;
            int j = hb;
            int t = 0;
            while (i < ta && j < tb)
                if (A[i] <= B[j])
                    tv[t++] = A[i++];
                else
                    tv[t++] = B[j++];

            while (i < ta) tv[t++] = A[i++];
            while (j < tb) tv[t++] = B[j++];
            return findMedian(tv, 0, ta - ha + tb - hb);
        }


        if (ta - ha == 2)
        {
            if ((tb - hb) % 2 == 0)
            {
                const int midl = (hb + tb - 1) / 2;
                const int midr = (hb + tb - 1) / 2 + 1;
                if (A[ha] >= B[midr] && A[ha] <= B[midr + 1])
                    return (A[ha] + B[midr]) / 2.0;
                if (A[ha + 1] <= B[midl] && A[ha + 1] >= B[midl - 1])
                    return (A[ha + 1] + B[midl]) / 2.0;
                if (A[ha] >= B[midl] && A[ha] <= B[midr])
                    return (A[ha] + min(A[ha+1], B[midr])) / 2.0;
                if (A[ha + 1] >= B[midl] && A[ha + 1] <= B[midr])
                    return (A[ha + 1] + max(A[ha], B[midl])) / 2.0;
            }
            else
            {
                const int mid = (hb + tb - 1) / 2;
                if (A[ha] >= B[mid] && A[ha] <= B[mid + 1])
                    return A[ha];
                if (A[ha + 1] <= B[mid] && A[ha + 1] >= B[mid - 1])
                    return A[ha + 1];
            }
        }

        const double median = findMedian(A, ha, ta);
        const int half = (ta - ha) / 2;
        
        int lb = lower_bound(B + hb, B + tb, median) - B;
        if (lb > hb + half)
            return findMedian(A, ha, ta - half, B, hb + half, tb);
        else
            return findMedian(A, ha + half, ta, B, hb, tb - half);
    }
    
    double
    findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        return findMedian(A, 0, m, B, 0, n);
    }


};

int
main(int argn, char** argv)
{
    int A[] = {1, 4, 5};
    int B[] = {2, 3, 6, 7, 8};
    Solution s;

    cout << s.findMedianSortedArrays(A, 3, B, 5) << endl;
}

// [1,2,5], [3,4,6,7,8]
