/*
 * Song Qiang <qiang.song@usc.edu> 2013
 *
 */


/*

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

 */

#include <cmath>

#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <limits>
#include <utility>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function


    	vector<string> ds;
		size_t n = 0;

		size_t s = 1;
		while (s != string::npos)
		{
			const size_t t = path.find_first_of('/', s);
			const string str =
				t == string::npos ? path.substr(s) : path.substr(s, t-s);

			if (str == "..") 
				n == 0 ? n : --n;
			else if (str != "." && str != "")
			{
				if (n == ds.size())
					ds.push_back(str);
				else
					ds[n] = str;
				++n;
			}

			s = t == string::npos ? string::npos : t + 1;
		}
		
        if (n == 0) return "/";
		string r;
		for (size_t i = 0; i < n; ++i)
			r += "/" + ds[i];

		return r;

    }
};




int
main(int argn, char** argv)
{
    Solution s;
}

