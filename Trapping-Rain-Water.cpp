/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

Given n non-negative integers representing an elevation map where the
width of each bar is 1, compute how much water it is able to trap
after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

The above elevation map is represented by array
[0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue
section) are being trapped. Thanks Marcos for contributing this image!

*/


#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <functional>


using namespace std;

class Solution {
public:

    struct Cmp: public binary_function<pair<int, int>, pair<int, int>, bool>
    {
        const bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
        {
            return lhs.first > rhs.first
                || (lhs.first == rhs.first && lhs.second > rhs.second);
        }
    };
    
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (n <= 2) return 0;

        vector<pair<int, int> > pv(n);
        for (size_t i = 0; i < n; ++i)
        {
            pv[i].first = A[i];
            pv[i].second = i;
        }

        vector<bool> good(n, true);
        sort(pv.begin(), pv.end(), Cmp());

        int w = 0;

        // search left
        int i = 0;
        int l = i + 1;
        while(l < n)
            if (pv[l].second > pv[i].second)
                ++l;
            else
            {
                if (l < n)
                {
                    const int g = min(pv[i].first, pv[l].first);
                    for (int j = pv[l].second + 1; j < pv[i].second; ++j)
                    {
                        w += (g - A[j]) * good[j];
                        good[j] = false;
                    }
                }
                i = l;
                l = i + 1;
            }
        
        // search right
        i = 0;
        int r = i + 1;
        while(r < n)
            if (pv[r].second < pv[i].second)
                ++r;
            else
            {
                if (r < n)
                {
                    const int g = min(pv[i].first, pv[r].first);
                    for (size_t j = pv[i].second + 1; j < pv[r].second; ++j)
                    {
                        w += (g - A[j]) * good[j];
                        good[j] = false;
                    }
                }
                i = r;
                r = i + 1;
            }
        return w;
    }
};


int
main(int argn, char** argv)
{
    Solution s;
    int A[] = {0, 2, 0};
    int n = 3;
    cout << s.trap(A, n) << endl;
}
