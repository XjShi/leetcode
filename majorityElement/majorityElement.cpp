/**
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
**/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums.front();
        int count = 0;
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter) {
            if (count == 0) {
                majority = *iter;
                count += 1;
            } else {
                if (majority == *iter) {
                    count += 1;
                } else {
                    if (--count <= 0)
                        majority = *iter;
                }
            }
        }
        return majority;
    }
};