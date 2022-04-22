// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    int goodNodes(TreeNode* root) {
        int result = 0;
        helper(root, INT_MIN, result);
        return result;
    }
    void helper(TreeNode* root, int maxVal, int &result) {
        if (root == NULL) {
            return;
        }
        if (root->val >= maxVal) {
            result++;
        }
        maxVal = max(maxVal, root->val);
        helper(root->left, maxVal, result);
        helper(root->right, maxVal, result);
    }
};