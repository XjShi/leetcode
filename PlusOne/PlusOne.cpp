/**
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
**/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int carry = 1;
        while (!digits.empty()) {
            int digit = digits.back();
            digits.pop_back();
            int sum = digit + carry;
            result.insert(result.begin(), sum % 10);
            carry = sum / 10;
        }
        if(carry != 0) {
            result.insert(result.begin(), carry);
        }
        return result;
    }
};