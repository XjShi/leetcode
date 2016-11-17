/**
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets
**/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int map[26] ={0} ;
        
        for (int i=0; i<s.size(); i++) {
            map[s[i]-'a']++;
        }
        for (int i=0; i<t.size(); i++) {
            map[t[i]-'a']--;
        }
        
        for (int i=0; i<sizeof(map)/sizeof(*map); i++) {
            if (map[i]!=0) return false;
        }
        return true;
    }
};