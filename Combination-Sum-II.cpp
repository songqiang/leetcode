/*
 * Song Qiang <qiang.song@usc.edu> 2012
 */


/*

Combination Sum II

Given a collection of candidate numbers (C) and a target number (T),
find all unique combinations in C where the candidate numbers sums to
T.

Each number in C may only be used once in the combination.

Note: All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending
order. (ie, a1 ≤ a2 ≤ … ≤ ak).

The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 

A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 

*/

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (candidates.empty()) return vector<vector<int> >();
        
        std::sort(candidates.begin(), candidates.end());
        
        vector<int> elements(1, candidates.front());
        vector<int> counts(1, 1);

        for (size_t i = 1; i < candidates.size(); ++i)
            if (candidates[i] == elements.back())
            {
                ++counts.back();
            }
            else
            {
                elements.push_back(candidates[i]);
                counts.push_back(1);
            }
        
        return combinationSum(elements, counts, 0, target);
    }

    vector<vector<int> >
    combinationSum(vector<int> &candidates, vector<int> &counts,
                   int idx, int target) {

        vector<vector<int> > r;
        if (idx == candidates.size() || candidates[idx] > target)
            return r;

        
        for (size_t i = 0; i <= std::min(counts[idx], target / candidates[idx]); ++i)
        {
            int target_reminder = target - candidates[idx] * i;
            if (target_reminder == 0)
                r.push_back(vector<int>(i, candidates[idx]));
            else
            {
                vector<vector<int> > t(combinationSum(candidates, couts, idx + 1,
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

