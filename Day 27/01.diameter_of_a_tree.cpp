// https://leetcode.com/problems/diameter-of-binary-tree/
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
    int result = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return result;
    }
    int helper(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int l = helper(node->left);
        int r = helper(node->right);
        result = max(result, l+r);
        return max(l, r) + 1;
    }
};