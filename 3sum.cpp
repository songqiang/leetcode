/*
 * 3sum: http://www.leetcode.com/2010/04/finding-all-unique-triplets-that-sums.html
 * Song Qiang <qiang.song@usc.edu> 2012-10-04
 *
 */

// time complexity: O(n^2)


class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {

        if (num.size() < 3) return vector<vector<int> >();

        
        std::sort(num.begin(), num.end());

        vector<vector<int> > r;
        
        vector<int> threenum(3);
        int i = 0;
        while (i < num.size() && num[i] + num.back() + num[num.size() - 2] < 0) ++i;
        
        while (i < num.size() - 2 && num[i] <= 0)
        {
            const int s = - num[i];
            threenum[0] = num[i];
            int h = i + 1, t = num.size() - 1;
            while (h < t)
            {
                if (num[h] + num[t] == s)
                {
                    threenum[1] = num[h];
                    threenum[2] = num[t];
                    if (r.empty() || r.back()  != threenum) r.push_back(threenum);
                    ++h;
                    --t;
                }
                else if (num[h] + num[t] < s)
                    ++h;
                else
                    --t;
            }
            
            ++i;
            while (i < num.size() && num[i] == num[i - 1]) ++i;
        }
        return r;

    }
};

