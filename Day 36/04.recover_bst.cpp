// https://leetcode.com/problems/recover-binary-search-tree/
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
    TreeNode* node1 = NULL;
    TreeNode* node2 = NULL;
    TreeNode* node = NULL;
    void recoverTree(TreeNode* root) {
        inorder(root);
        int val = node1->val;
        node1->val = node2->val;
        node2->val = val;
    }
    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        if (node != NULL && root->val < node->val) {
            if (node1 == NULL) {
                node1 = node;
                node2 = root;
            } else {
                node2 = root;
            }
        }
        node = root;
        inorder(root->right);
    }
};