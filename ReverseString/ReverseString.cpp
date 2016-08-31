/*
 *	反转字符串
 */

class Solution {
public:
	string reverseString(string s) {
		int len = s.size();
		for (int i = 0; i < len / 2; ++i) {
			char ch = s[i];
			s[i] = s[len-1-i];
			s[len-1-i] = ch;
		}
		return s;
	}
};