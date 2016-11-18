/**
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
**/

/**
递归回溯: 
	1.递归一次，填入一个数字 
	2.填入的数字，不能是小于当前数字的值，防止重复 
	3.回溯：记得pop_back()最后加上的一个数字，回溯到上一层。 
	4.结束条件：填写够了k个数字的时候，当前填写完毕，回溯
**/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
    	vector<vector<int> > result;
    	vector<int> path;
    	dfs(n, k, result, path, 1);
    	return result;
    }

private:
	void dfs(int n, int k, vector<vector<int> > &result, vector<int> &path, int index) {
		if (path.size() == k) {
			result.push_back(path);
			return;
		}
		for (int i = index; i <= n; ++i) {
			path.push_back(i);
			dfs(n, k, result, path, i+1);
			path.pop_back();
		}
	}
};