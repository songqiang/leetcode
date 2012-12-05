/*
 * 3sum: http://www.leetcode.com/2010/04/finding-all-unique-triplets-that-sums.html
 * Song Qiang <qiang.song@usc.edu> 2012-10-04
 *
 */

// time complexity: O(n^2)

class Solution 
{
public:
    vector<vector<int> > twoSum(vector<int> &num, const int s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        assert(num.size() >= 2);
        std::sort(num.begin(), num.end());
        
        std::set<vector<int> > r;
        size_t h = 0, t = num.size() - 1;
        while (h != t)
        {
            const int sum2 = num[h] + num[t];
            if (sum2 == s)
            {
                vector<int> ns;
                ns.push_back(num[h]);
                ns.push_back(num[t]);
                r.push(ns);
                ++h;
                --t;
            }
            else if (sum2 < s)
                ++h;
            else
                --t;
        }
    }
    
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        std::sort(num.begin(), num.end());

        vector<vector<int> > r;
        
        vector<int> threenum(3);
        for (size_t i = 0; i < num.size() - 2; ++i)
        {
            if (num[i] > 0) break;
            const int s = - num[i];
            threenum[0] = num[i];
            size_t h = i + 1, t = num.size() - 1;
            while (h < t)
            {
                if (num[h] + num[t] == s)
                {
                    threenum[1] = num[h];
                    threenum[2] = num[t];
                    if (r.empty()
                        || mismatch(r.back().begin(), r.back().end(), threenum.begin()) == r.back().end())
                        r.push_back(threenum);
                    ++h;
                    --t;
                }
                else if (num[h] + num[t] < s)
                    ++h;
                else
                    --t;
            }
        }
        return r;
    }
};
