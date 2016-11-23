/**
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
**/

class Solution {
public:
    int firstUniqChar(string s) {
        int map[26] = {0};
        for (string::iterator iter = s.begin(); iter!= s.end(); ++iter) {
            map[*iter - 'a']++;
        }
        for (string::iterator iter = s.begin(); iter!= s.end(); ++iter) {
            if (map[*iter - 'a'] == 1)
                return iter - s.begin();
        }
        return -1;
    }
};