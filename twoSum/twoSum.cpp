/**
	Given an array of integers, return indices of the two numbers such that they add up to a specific target.

	You may assume that each input would have exactly one solution.

	Example:
	Given nums = [2, 7, 11, 15], target = 9,

	Because nums[0] + nums[1] = 2 + 7 = 9,
	return [0, 1].
**/

#include <iostream>
using namespace std;

#define NOT_FOUND -1

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	std::vector<int> result;
        for (std::vector<int>::size_type index = 0; index != nums.size(); index++) {
        	int curValue = nums[index];
        	int sub = target - curValue;
        	int subIndex = findValue(nums, sub, index);
        	if (NOT_FOUND != subIndex) {
        		result.push_back(index);
        		result.push_back(subIndex);
        		return;
        	}
        }
    }
private:
	int findValue(std::vector<int>& nums, int value, int exceptIndex) {
		for (std::std::vector<int>::size_type index = 0; index != nums.size(); index++) {
			if(nums[index] == value && exceptIndex != index)
				return index;
		}
		return NOT_FOUND;
	}
};