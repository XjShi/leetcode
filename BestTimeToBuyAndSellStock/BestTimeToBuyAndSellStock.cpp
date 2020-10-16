/*
 Leetcode 121: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 */

#include <vector>
#include <limits.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int minPrice = prices[0];
        // maxProfit[k] 表示前k天卖出的最大收益
        vector<int> maxProfit(prices.size());
        maxProfit[0] = 0;
        for (int i = 1; i < prices.size(); ++i) {
            maxProfit[i] = max(maxProfit[i - 1], prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit[prices.size() - 1];
    }
};

/*
 相比最原始的方案，该方案压缩了maxProfit，节省了空间
 */
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int minPrice = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            maxProfit = max(maxProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};

/*
 还可以转换为 max subarray 来解决
 */