// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        helper(root);
    }
    void helper(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        helper(node->left);
        helper(node->right);
        TreeNode* temp = node->right;
        if (node->left != NULL) {
            node->right = node->left;
            node->left = NULL;
            while(node->right != NULL) {
                node = node->right;
            }
            node->right = temp;
        }
    }
};