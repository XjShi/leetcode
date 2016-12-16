/**
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

Assume that your function returns 0 when the reversed integer overflows.
**/

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    /**
     考虑一些特殊情况，比如0，100，越界，个位数
     **/
    int reverse(int x) {
        if (x < 10 && x > -10)
            return x;
        
        int sign = x > 0 ? 1 : -1;
        int result = 0;
        x = abs(x);
        while(x / 10 != 0) {				//x:253	25
            result = result * 10 + x % 10;	//3 	35
            x = x / 10;						//25 	2
        }
        if (result > (INT_MAX - x) / 10 || -result*10 < INT_MIN + x) {
            return 0;
        } else {
            result = result * 10 + x;
            return sign * result;
        }
    }
};

int main() {
    Solution s = Solution();
    cout << s.reverse(253) << endl;
    cout << s.reverse(0) << endl;
    cout << s.reverse(-0) << endl;
    cout << s.reverse(-100) << endl;
}