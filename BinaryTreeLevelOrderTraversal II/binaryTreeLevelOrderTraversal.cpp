/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void traversal(TreeNode *node, int level, vector<vector<int> >& result) {
        if (node == NULL)   return;
        result[level].push_back(node->val);
        if (node->left != NULL) traversal(node->left, level+1, result);
        if (node->right != NULL)    traversal(node->right, level+1, result);    
    }
    
    int depth(TreeNode* root) {
        if (root == NULL)   return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int dep = depth(root);
        vector<vector<int> > result(dep);
        traversal(root, 0, result);
        reverse(result.begin(), result.end());
        return result;
    }
};