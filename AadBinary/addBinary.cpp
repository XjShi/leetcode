/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        string::size_type lA = a.length();
        string::size_type lB = b.length();
        if (lA < lB) {
            a.insert(0, lB-lA, '0');
        }
        if (lA > lB) {
            b.insert(0, lA-lB, '0');
        }
        int carry = 0;
        int i, j;
        for (i = a.length()-1,j = b.length()-1; i>=0 && j>=0; --i,--j) {
            int numA = stoi(a.substr(i,1)), numB = stoi(b.substr(j,1));
            int sum = numA + numB + carry;
            carry = sum / 2;
            string tmp = sum % 2 ? "1" : "0";
            result = tmp + result;
        }
        if (carry > 0) {
            result.insert(0, "1");
        }
        return result;
    }
};