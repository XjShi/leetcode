/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
*/

class Solution {
public:
    int addDigits(int num) {
        while(num > 9) {
            int sum = 0;
            for(; num > 0; sum += num%10, num /= 10);
            num = sum;
        }
        return num;
    }

    int addDigits1(int num) {
    	return num < 9 ? num : (num%9 == 0 ? 9 : num%9);
    }

    int addDigits2(int sum) {
    	return (num - 1) % 9 + 1;
    }
}