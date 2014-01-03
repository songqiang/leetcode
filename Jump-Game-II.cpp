/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

Given an array of non-negative integers, you are initially positioned
at the first index of the array.

Each element in the array represents your maximum jump length at that
position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step
from index 0 to 1, then 3 steps to the last index.)

*/


class Solution {
public:

    int jump(int A[], int n) {
        
        if (n <= 1) return 0;
        
        vector<int> steps(n, numeric_limits<int>::max());
        
        steps[0] = 0;
        int prev_end = 0, end;
        for (int i = 0; i < n; ++i)
        {
            end = min(max(prev_end, i + A[i] + 1), n);
            std:fill(steps.begin() + prev_end, steps.begin() + end, steps[i] + 1);
            prev_end = end;
        }
        return steps.back();
    }


    int jump_first_solution(int A[], int n) {
        
        if (n <= 1) return 0;
        
        vector<int> steps(n, numeric_limits<int>::max());
       
        vector<int> projections(n, 0);
       
        steps[0] = 0;
        projections[0] = A[0];
        for (int j = 1; j <= min(A[0], n - 1); ++j)
            steps[j] = 1;

        for (int i = 1; i < n; ++i)
        {
            projections[i] = min(max(projections[i - 1], i + A[i]), n - 1);
            for (size_t j = projections[i - 1] + 1; j <= projections[i]; ++j)
                steps[j] = steps[i] + 1;
        }
        return steps.back();
    }

};


