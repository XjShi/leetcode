/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
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
	//Recursive
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL)   return result;
        vector<int> left = inorderTraversal(root->left);
        result.insert(result.begin(), left.begin(), left.end());
        result.push_back(root->val);
        vector<int> right = inorderTraversal(root->right);
        result.insert(result.end(), right.begin(), right.end());
        return result;
    }
    
};