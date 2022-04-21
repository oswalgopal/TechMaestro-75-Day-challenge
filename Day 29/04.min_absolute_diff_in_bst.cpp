// https://leetcode.com/problems/minimum-absolute-difference-in-bst/
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
    int prev = -1;
    int getMinimumDifference(TreeNode* root) {
        int result = INT_MAX;
        helper(root, result);
        return result;
    }
    void helper(TreeNode* node, int &result) {
        if (node == NULL) {
            return;
        }
        helper(node->left, result);
        if (prev != -1) {
            result = min(result, node->val-prev);
        }
        prev = node->val;
        helper(node->right, result);
    }
};