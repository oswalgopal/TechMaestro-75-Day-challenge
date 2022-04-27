// https://leetcode.com/problems/validate-binary-search-tree/

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
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
    bool helper(TreeNode* node, TreeNode* low, TreeNode* high) {
        if (node == NULL) {
            return true;
        }
        if ((low != NULL && node->val <= low->val) || (high != NULL && node->val >= high->val)) {
            return false;
        } 
        return helper(node->left, low, node) && helper(node->right, node, high);
    }
};