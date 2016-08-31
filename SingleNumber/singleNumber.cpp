/*
 *	Given an array of integers, every element appears twice except for one. Find that single one.
 *
 * 	Note:
 *	Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */
 #import <iostream>
 using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
        {
        	sum ^= *i;
        }
        return sum;
    }
};

int main() {
	Solution *s = new Solution();
	s->singleNumber
}