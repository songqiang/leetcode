/*
 * anagrams
 * http://www.cnblogs.com/etcow/archive/2012/06/29/2568922.html
 * Song Qiang <qiang.song@usc.edu> 2012-10-10
 * 
 * test passed
 */

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<std::pair<string, string> > v(strs.size());
        
        for (size_t i = 0; i < strs.size(); ++i)
        {
            v[i].first = v[i].second = strs[i];
            std::sort(v[i].first.begin(), v[i].first.end());
        }

        std::sort(v.begin(), v.end());

        vector<string> r;
        vector<std::pair<string, string> > tmp;

        for (size_t i = 0; i < v.size(); ++i)
        {
            if (tmp.size() > 0 && tmp.back().first != v[i].first)
            {
                if (tmp.size() > 1)
                    for (size_t j = 0; j < tmp.size(); ++j)
                        r.push_back(tmp[j].second);
                tmp.clear();
            }
            tmp.push_back(v[i]);
        }

        if (tmp.size() > 1)
            for (size_t j = 0; j < tmp.size(); ++j)
                r.push_back(tmp[j].second);

        return r;
    }

    vector<string> anagrams(vector<string> &strs) {
        // use frequency array 
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        struct vec_less: public std::binary_function<vector<size_t>, vector<size_t>, bool>
        {
            bool operator()(const vector<size_t> &v1,
                            const vector<size_t> &v2) const
            {
                return std::mismatch(v1.begin(), v1.end(), v1.begin(),
                                     std::less<size_t>()).first == v1.end();
            }
        }

        struct vec_equal: public std::binary_function<vector<size_t>, vector<size_t>, bool>
        {
            bool operator()(const vector<size_t> &v1,
                            const vector<size_t> &v2) const
            {
                return std::mismatch(v1.begin(), v1.end(), v1.begin(),
                                     std::equal<size_t>()).first == v1.end();
            }
        }

        vector<std::pair<vector<size_t>, size_t> > v(strs.size());
        
        for (size_t i = 0; i < strs.size(); ++i)
        {
            v[i].second = i;
            vector<size_t> f(27);
            f[0] = strs[i].size();
            for (size_t j = 0; j < strs[i].size())
                ++f[strs[i][j] - ord('a') + 1];
        }

        std::sort(v.begin(), v.end(), vec_less());

        vector<string> r;
        vector<std::pair<vector<size_t>, size_t> > tmp;

        for (size_t i = 0; i < v.size(); ++i)
        {
            if (tmp.size() > 0
                && !vec_equal().operator()(tmp.back().first, v[i].first))
            {
                if (tmp.size() > 1)
                    for (size_t j = 0; j < tmp.size(); ++j)
                        r.push_back(strs[tmp[j].second]);
                tmp.clear();
            }
            tmp.push_back(v[i]);
        }

        if (tmp.size() > 1)
            for (size_t j = 0; j < tmp.size(); ++j)
                r.push_back(strs[tmp[j].second]);

        return r;
    }
};

