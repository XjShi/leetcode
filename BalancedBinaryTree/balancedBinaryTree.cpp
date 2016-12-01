/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which
 the depth of the two subtrees of every node never differ by more than 1.
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

/**
可以在现在基础上，存储每个计算过的节点的高度
**/
class Solution {
public:
    int depth(TreeNode *node) {
        if (!node)  return 0;
        if (!node->left && !node->right)    return 1;
        return max(depth(node->left), depth(node->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (!root)  return true;
        int sub = depth(root->left) - depth(root->right);
        if (abs(sub) > 1) {
            return false;
        }
        else {
            return isBalanced(root->left) && isBalanced(root->right);
        }
    }
};