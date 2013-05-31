/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

Given an array of integers, find two numbers such that they add up to
a specific target number.

The function twoSum should return indices of the two numbers such that
they add up to the target, where index1 must be less than
index2. Please note that your returned answers (both index1 and
index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

*/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        struct Cmp : public binary_function<pair<int, int>, pair<int, int>, bool>
        {
            const bool operator()(const pair<int, int> &lhs,
                                  const pair<int, int> &rhs) const
            {
                return lhs.first < rhs.first
                    || (lhs.first == rhs.first && lhs.second < rhs.second);
            }
        }
        
        vector<pair<int, int> > pv(numbers.size());
        for (size_t i = 0; i < numbers.size(); ++i)
        {
            pv[i].first = numbers[i];
            pv[i].second = i;
        }

        sort(pv.begin(), pv.end(), Cmp());
        
        int h = 0;
        int t = pv.size() - 1;

        vector<int> r;
        while (h < t)
        {
            const int s = pv[h].first + pv[t].first;
            if (s < target)
                h += 1;
            else if (s > target)
                t -= 1;
            else
            {
                r.push_back(pv[h].second + 1);
                r.push_back(pv[t].second + 1);
                if (r.front() > r.back()) swap(r.front(), r.back());
                return r;
            }
        }

    }
};
