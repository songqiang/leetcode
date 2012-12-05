/*
 * 3sum closest: 
 * http://stackoverflow.com/questions/2070359/finding-three-elements-in-an-array-whose-sum-is-closest-to-an-given-number
 * 
 * Song Qiang <qiang.song@usc.edu> 2012-10-04
 *
 */

// time complexity: O(n^2)

class Solution 
{
public:
    vector<vector<int> > twoSumClosest(vector<int> &num, const int s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        assert(num.size() >= 2);
        std::sort(num.begin(), num.end());
        
        vector<int> r(2);
        int min_delta = std::numeric_limits<int>::max();

        size_t h = 0, t = num.size() - 1;
        while (h != t)
        {
            const int sum2 = num[h] + num[t];
            if (abs(sum2 - s) < min_delta)
            {
                r[0] = num[h];
                r[1] = num[t];
                min_delta = abs(sum2 - s);
            }
            if (sum2 > s)
                --t;
            else if (sum2 <= s)
                ++h;
        }
        return r;
    }
    
    vector<vector<int> > threeSumClosest(vector<int> &num, const int s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        std::sort(num.begin(), num.end());

        vector<int> threenum(3);
        int min_delta = std::numeric_limits<int>::max();

        for (size_t i = 0; i < num.size() - 2; ++i)
        {
            const int sp = s - threenum[0];
            size_t h = i + 1, t = num.size() - 1;
            while (h < t)
            {
                const int sum2 = num[h] + num[t];
                if (abs(sum2 - sp) < min_delta)
                {
                    threenum[0] = num[i];
                    threenum[1] = num[h];
                    threenum[2] = num[t];
                    min_delta = abs(sum2 - sp);
                }
                if (sum2 > sp)
                    --t;
                else if (sum2 < sp) 
                    ++h;
                else
                    break;
            }
        }
        return threenum;
    }
};
