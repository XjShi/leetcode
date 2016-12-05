/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

class Solution {
public:
	// 关键点在于num & ~(num-1)
    vector<int> singleNumber(vector<int>& nums) {
        int result = 0;
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter) {
            result ^= *iter;
        }
        
        int mask = result & ~(result - 1);
        int a = 0, b = 0;
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter) {
            if (*iter & mask) {
                a ^= *iter;
            } else {
                b ^= *iter;
            }
        }
        vector<int> vec;
        vec.push_back(a);
        vec.push_back(b);
        return vec;
    }
};