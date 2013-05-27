/*
 * Song Qiang <qiang.song@usc.edu> 2013
 */


/*

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// remember to sort first

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (intervals.empty()) return vector<Interval>();
        
        struct less : public binary_function<Interval, Interval, bool>
        {
            bool operator()(const Interval &a, const Interval &b)
            {
                return a.start < b.start;
            }
        };

        sort(intervals.begin(), intervals.end(), less());

        vector<Interval> result;
        result.push_back(intervals.front());
        size_t i = 1;
        while (i < intervals.size())
        {	
            if (intervals[i].start <= result.back().end)
                result.back().end = max(result.back().end, intervals[i].end);
            else
                
                result.push_back(intervals[i]);
            ++i;
        } 
 
        return result;

    }
};


