// https://leetcode.com/problems/sum-of-left-leaves/
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
    int sumOfLeftLeaves(TreeNode* root) {
       int result = 0;
        helper(root, result, -1);
       return result;
    }
    void helper(TreeNode* root, int &result, int leftFlag) {
        if (root == NULL) {
            return;
        }
        if (leftFlag == 1 && root->left == NULL && root->right == NULL) {
            result += root->val;
            return;
        }
        helper(root->left, result, 1);
        helper(root->right, result, -1);
    }
};