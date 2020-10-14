/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (string::iterator iter = s.begin(); iter != s.end(); ++iter) {
            if (stk.empty()) {
                stk.push(*iter);
            } else {
                char last = stk.top();
                if (last == getCorresponding(*iter)) {
                    stk.pop();
                } else {
                    stk.push(*iter);
                }
            }
        }
        return stk.empty();
    }

    static char getCorresponding(char c) {
        switch (c) {
            case ')':   return '('; 
                break;
            case ']':   return '[';
                break;
            case '}':   return '{';
                break;
            default:
                return ' ';
        }
    }
};