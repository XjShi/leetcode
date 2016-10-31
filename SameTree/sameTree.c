/*
 *	Given two binary trees, write a function to check if they are equal or not.
 *
 *	Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL)
		return true;
	if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) 
		return false;

	if (p->value != q->value) {
		return false;
	} else {
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
}