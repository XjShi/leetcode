/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

// another solution is using xor
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(*nums.begin() != 0) {
            return 0;
        }
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end() - 1; ++iter) {
            if (*(iter+1) - *iter != 1) {
                return *iter + 1;
            }
        }
        return *(nums.end() - 1) + 1;
    }
};