/*
 *	Given a binary tree, return all root-to-leaf paths.
 *
 *	For example, given the following binary tree:
 *
 *	   1
 *	 /   \
 *	2     3
 *	 \
 *	  5
 *	All root-to-leaf paths are:
 *
 *	["1->2->5", "1->3"]
 */


// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	void dfs(TreeNode *root, string str, vector<string>& result) {
		if (str == "")
			str = to_string(root->val);
		else
			str = str + "->" + to_string(root->val);
		if (!root->left && !root->right)
			result.push_back(str);
		if (root->left)
			dfs(root->left, str, result);
		if (root->right)
			dfs(root->right, str, result);
	}

    vector<string> binaryTreePaths(TreeNode* root) {
    	if (!root) {
    		return vector<string>();
    	}
    	vector<string> result;
    	dfs(root, "", result);
    	return result;
    }
};