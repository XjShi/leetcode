/**
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
**/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>::iterator zeroIter = nums.begin();
        for (vector<int>::iterator iter = nums.begin(); iter!=nums.end(); iter++) {
            if (*iter != 0) {
                swap(*zeroIter++, *iter);
            }
        }
    }
};