/**
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
**/

class Solution {
public:
    void func(vector<vector<int> >& result, TreeNode* root, int depth) {
        if (!root)  return;
        result[depth].push_back(root->val);
        if (root->left)
            func(result, root->left, depth+1);
        if (root->right)
            func(result, root->right, depth+1);
    }
    
    int depth(TreeNode* root) {
        if (!root)
            return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > result(depth(root));
        func(result, root, 0);
        return result;
    }
};