
#include <vector>
#include <limits.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int length = nums.size();
        int dp[length];
        dp[0] = nums[0];

        /*
         对于dp[i]，如果dp[i-1]小于0，那么另起炉灶。
         
         也可以简化为 max(num[i], num[i] + d[i-1]
         */
        for (int i = 1; i < length; ++i) {
            if (dp[i - 1] < 0) {
                dp[i] = nums[i];
            } else {
                dp[i] = nums[i] + dp[i - 1];
            }
        }

        int res = INT_MIN;
        for (int i = 0; i < length; i++) {
            res = max(res, dp[i]);
        }
        return res;
    }
};

/*
 实际上dp[i]这个当前状态仅于dp[i-1]这个上一个状态有关。可以简化如下
 */
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        int length = nums.size();
        if (length == 0) {
            return 0;
        }

        int prev = nums[0];
        int res = prev;
        for (int i = 1; i < length; ++i) {
            prev = max(nums[i], nums[i] + prev);
            res = max(res, prev);
        }
        return res;
    }
};

int main() {
	vector<int> arr = {1, 2, 3, 4};
	Solution s = Solution();
	int res = s.maxSubArray(arr);
	cout << res << endl;
}