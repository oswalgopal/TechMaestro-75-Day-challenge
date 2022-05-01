// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int count = 0;
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) {
            return -1;
        }
        int l = kthSmallest(root->left, k);
        count++;
        if (count == k) {
            return root->val;
        }
        int r = kthSmallest(root->right, k);
        return max(l, r);
    }
};