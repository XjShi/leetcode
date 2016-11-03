/**
Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

	1.The length of both num1 and num2 is < 5100.
	2.Both num1 and num2 contains only digits 0-9.
	3.Both num1 and num2 does not contain any leading zero.
	4.You must not use any built-in BigInteger library or convert the inputs to integer directly.
**/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        int carry = 0;
        while(num1.size()>0 && num2.size()>0) {
            char c1 = num1.back();
            char c2 = num2.back();
            num1.erase(num1.end() - 1);
            num2.erase(num2.end() - 1);
            int sum = myAtoi(c1) + myAtoi(c2) + carry;
            result.insert(result.begin(), myItoa(sum % 10));
            carry = sum / 10;
        }
        
        string tmp;
        if (num1.size() > 0) {
            tmp = num1;
        }
        if (num2.size() > 0) {
            tmp = num2;
        }
        while (tmp.size() > 0) {
            char c2 = tmp.back();
            tmp.erase(tmp.end() - 1);
            int sum = myAtoi(c2) + carry;
            result.insert(result.begin(), myItoa(sum % 10));
            carry = sum / 10;
        }
        
        if (carry > 0) {
            result.insert(result.begin(), '1');
        }
        return result;
    }
    
private:
    static int myAtoi(const char c) {
        return c - '0';
    }
    //形参i需要小于10
    static char myItoa(const int i) {
        return '0' + i;
    }
};

int main() {
	string s1("193");
	string s2("2387");
	Solution *s = new Solution();
	cout << s->addStrings(s1, s2) << endl;
}