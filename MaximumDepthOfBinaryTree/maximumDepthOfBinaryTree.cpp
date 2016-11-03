/**
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
**/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <queue>


class Solution {
public:
	/**
	如果root为空，返回0；
	如果root不为空，但没有子节点，返回1；
	否则，递归计算子树高度
	**/
    int maxDepth(TreeNode* root) {
        if (!root)	
        	return 0;
        if (!root->left && !root->right) 	
        	return 1;

        int lH = 1, rH = 1;
        if (root->left) 
        	lH += maxDepth(root->left);
        if (root->right)
        	rH += maxDepth(root->right);
        return lH > rH ? lH : rH;
    }
};