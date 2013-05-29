/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

Given two numbers represented as strings, return multiplication of the
numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

*/

// not tested yet


class Solution {
public:
    void
    add_to(vector<int> &result, const vector<int> &n, const size_t offset = 0)
    {
        result.resize(max(result.size(), n.size() + offset), 0);

        int inc = 0;
        for (size_t i = 0; i < n.size(); ++i)
        {
            result[i + offset] += n[i] + inc;
            inc = result[i + offset] / 10;
            result[i + offset] %= 10;
        }

        for (size_t i = n.size() + offset; i < result.size(); ++i)
        {
            result[i] += inc;
            inc = result[i] / 10;
            result[i] %= 10;
            if (inc == 0) break;
        }

        if (inc > 0) result.push_back(inc);
    }

    void
    times_to(vector<int> &result, const int n)
    {
        assert(n >= 0 && n <= 9);
        int inc = 0;
        for (size_t i = 0; i < result.size(); ++i)
        {
            result[i] = result[i] * n + inc;
            inc = result[i] / 10;
            result[i] %= 10;
        }

        if (inc > 0) result.push_back(inc);
    }

    void
    str_to_vec(const string &s, vector<int> &v)
    {
        v.clear();
        const int n = s.size();
        for (size_t i = 0; i < s.size(); ++i)
            v.push_back( s[n - 1 - i] - 48 );

        while (v.size() > 1 && v.back() == 0) v.pop_back();
    }

    void
    vec_to_str(const vector<int> &v, string &s)
    {
        ostringstream oss;
        const int n = v.size();
        for (size_t i = 0; i < v.size(); ++i)
            oss << v[n - 1 - i];
        s = oss.str();
    }

    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<int> n1, n2;
        str_to_vec(num1, n1);
        str_to_vec(num2, n2);

        if (n1.size() < n2.size()) swap(n1, n2);
        
        // cache
        vector<vector<int> > cache(10, n1);
        for (size_t i = 2; i < 10; ++i)
            add_to(cache[i], cache[i - 1]);


        // add
        vector<int> result(1, 0);
        for (size_t i = 0; i < n2.size(); ++i)
            if (n2[i] > 0)
                add_to(result, cache[n2[i]], i);
        
        string s;
        vec_to_str(result, s);
        return s;
    }
};
