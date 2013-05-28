/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

Given an array of non-negative integers, you are initially positioned
at the first index of the array.

Each element in the array represents your maximum jump length at that
position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

*/


class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<int> stepping_stones(n, -1);
        stepping_stones[n - 1] = n - 1;
        for (int i = n - 2; i >= 0 ; --i)
        {
            if (i + A[i] >= stepping_stones[i+1])
                stepping_stones[i] = i;
            else
                stepping_stones[i] = stepping_stones[i+1];
        }

        return stepping_stones[0] == 0;
    }
};


