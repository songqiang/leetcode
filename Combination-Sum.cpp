/*
 * Song Qiang <qiang.song@usc.edu> 2012
 */


/*

Combination Sum 

Gien a set of candidate numbers (C) and a target number (T), find all
unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of
times.

Note:
All numbers (including target) will be positive integers.


Elements in a combination (a1, a2, … , ak) must be in non-descending
order. (ie, a1 ≤ a2 ≤ … ≤ ak).

The solution set must not contain duplicate combinations.  For
example, given candidate set 2,3,6,7 and target 7,

A solution set is: 
[7] 
[2, 2, 3] 

*/

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        std::sort(candidates.begin(), candidates.end());

        return combinationSum(candidates, 0, target);
    }

    vector<vector<int> >
    combinationSum(vector<int> &candidates, int idx, int target) {

        vector<vector<int> > r;
        if (idx == candidates.size() || candidates[idx] > target)
            return r;

        
        for (size_t i = 0; i <= target / candidates[idx]; ++i)
        {
            int target_reminder = target - candidates[idx] * i;
            if (target_reminder == 0)
                r.push_back(vector<int>(i, candidates[idx]));
            else
            {
                vector<vector<int> > t(combinationSum(candidates, idx + 1,
                                                      target_reminder));
                for (size_t j = 0; j < t.size(); ++j)
                {
                    r.push_back(vector<int>(i, candidates[idx]));
                    std::copy(t[j].begin(), t[j].end(),
                              std::back_inserter(r.back())); 
                }
            }
        }
        return r;
    }
}

