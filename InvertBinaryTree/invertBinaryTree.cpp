/**
	Invert a binary tree.

	     4
	   /   \
	  2     7
	 / \   / \
	1   3 6   9
	to
	     4
	   /   \
	  7     2
	 / \   / \
	9   6 3   1
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
        	return root;
        
        TreeNode *node = invertTree(root->right);
        root->right = invertTree(root->left);
        root->left = node;
        return root;
    }

    TreeNode* invertTree_iterative(TreeNode *root) {
    	if (root == NULL)
    		return root;

    	stack<TreeNode *> stack;
    	stack.push_back(root);
    	while(!stack.empty()) {
    		TreeNode *node = stack.top();
    		TreeNode *tmp = node->left;
    		node->left = node->right;
    		node->right = tmp;

    		stack.push(node->left);
    		stack.push(node->right);
    	}
    	return stack;
    }
};