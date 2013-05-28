/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].


*/

class Solution {
public:

    void permute(int n, vector<int> &v, vector<vector<int> > &result)
    {
        if (n == v.size())
        {
            result.push_back(v);
            return;
        }
        
        vector<int> snapshot(v.begin() + n, v.end());
        for (size_t i = n; i < v.size(); ++i)
        {
            swap(v[n], v[i]);
            permute(n + 1, v, result);
            copy(snapshot.begin(), snapshot.end(), v.begin() + n);
        }
    }
    
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<vector<int> > result;
        
        permute(0, num, result);
        return result;
    }

};
