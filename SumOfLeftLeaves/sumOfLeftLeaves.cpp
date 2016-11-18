/**
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
        	return 0;
        int sum = 0;
        stack<TreeNode *> nodeStack;
        nodeStack.push(root);
        while (nodeStack.empty() == false) {
        	TreeNode *node = nodeStack.top();
        	nodeStack.pop();
        	if (!node->left && !node->right) {
        		sum += node->val;
        	}
        	if (node->left) {
        		nodeStack.push(node->left);
        	}
        	if (node->right) {
        		nodeStack.push(node->right);
        	}
        }
        return sum;
    }
};