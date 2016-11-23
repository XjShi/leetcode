/**
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
**/

class Solution {
public:
    string reverseVowels(string s) {
        if (s.length() < 2)
            return s;
        for (int left = 0, right = s.length() - 1; left < right; ) {
            if (!isVowel(s[left]))
                left++;
            if (!isVowel(s[right]))
                right--;
            if (isVowel(s[left]) && isVowel(s[right])) {
                char tmp = s[left];
                s[left] = s[right];
                s[right] = tmp;
                left++;
                right--;
            }
        }
        return s;
    }
private:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return true;
        } else {
            return false;
        }
    }
};