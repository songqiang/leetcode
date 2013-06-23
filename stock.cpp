/*

Best Time to Buy and Sell Stock Say you have an array for which the
ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie,
buy one and sell one share of the stock), design an algorithm to find
the maximum profit.

 */

// allow both short and long
class Solution 
{
public:
    int maxProfit(vector<int> &prices) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (prices.size() < 2) return 0;
        
        int min = std::numeric_limits<int>::max();
        int max = std::numeric_limits<int>::min();
        for (size_t i = 0; i < prices.size(); ++i)
        {
            if (prices[i] > max) max = prices[i];
            if (prices[i] < min) min = prices[i];
        }

        return max - min;
    }
};


// allow only long
class Solution 
{
public:
    int maxProfit(vector<int> &prices) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (prices.size() == 0) return 0;
        
        vector<int> mins(prices.size(), std::numeric_limits<int>::max());
        mins[0] = prices[0];
        for (size_t i = 1; i < prices.size(); ++i)
            mins[i] = std::min(mins[i-1], prices[i]);

        int p = prices[0] - mins[0];
        for (size_t i = 1; i < mins.size(); ++i)
            p = std::max(prices[i] - mins[i], p);
        
        return p;
    }
};


/*
Best Time to Buy and Sell Stock II Say you have an array for which the
ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as
many transactions as you like (ie, buy one and sell one share of the
stock multiple times). However, you may not engage in multiple
transactions at the same time (ie, you must sell the stock before you
buy again). 
 */

class Solution 
{
public:
    int maxProfit(vector<int> &prices) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        // strategy: hold until price dips
        if (prices.size() <= 1) return 0;

        const size_t n = prices.size();
        
        vector<int> p(n, 0);
        vector<int> hold(prices);

        hold[0] = prices[0];
        for (size_t i = 1; i < n; ++i)
        {
            if (prices[i - 1] > prices[i])
            {
                p[i] += p[i-1] + std::max(0, prices[i - 1] - hold[i - 1]);
                hold[i] = prices[i];
            }
            else
            {
                p[i] = p[i-1];
                hold[i] = std::min(prices[i], hold[i - 1]);
            }
        }

        return p.back() + std::max(0, prices.back() - hold.back());
    }
};


/*
Best Time to Buy and Sell Stock III Say you have an array for which
the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at
most two transactions.

Note: You may not engage in multiple transactions at the same time
(ie, you must sell the stock before you buy again).
 
*/

class Solution 
{
public:
    int maxProfit(vector<int> &prices) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        // strategy: hold until price dips
        if (prices.size() <= 1) return 0;

        const size_t n = prices.size();
        
        vector<int> p1(n, 0);
        vector<int> hold(prices);

        hold[0] = prices[0];
        for (size_t i = 1; i < n; ++i)
        {
            hold[i] = std::min(hold[i - 1], prices[i]);
            p1[i] = prices[i] - hold[i];
        }

        std::copy(prices.begin(), prices.end(), hold.begin()); 

        int p = std::max(p1[0], p1[1]);
        for (size_t i = 2; i < n; ++i)
        {
            if (prices[i-1] > prices[i] && prices[i-1] >=  prices[i-2])
            {
                int p2 = 0;
                hold[i] = prices[i];
                for (size_t j = i+1; j < n; ++j)
                {
                    hold[j] = std::min(hold[j-1], prices[j]);
                    p2 = std::max(prices[j] - hold[j], p2);
                }
                p = std::max(p, p2 + p1[i-1]);
            }
            p = std::max(p, p1[i]);
        }
        return p;
    }
};

