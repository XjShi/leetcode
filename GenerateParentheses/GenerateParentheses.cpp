/*
https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        if (n > 0) dfs(n, n, cur, ans);
        return ans;
    }
private:
    void dfs(int l, int r, string& s, vector<string>& ans) {
        if (l + r == 0) {
            ans.push_back(s);
            return;
        }
        if (r < l) return;
        if (l > 0) {
            dfs(l - 1, r, s += "(", ans);
            s.pop_back();
        }
        if (r > 0) {
            dfs(l, r - 1, s += ")", ans);
            s.pop_back();
        }
    }
};