// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        helper(root, target, k, result);
        return result;
    }
    void dfs(TreeNode* node, int dist, int d, vector<int> &result) {
        if (node == NULL) {
            return;
        }
        if (dist == d) {
            result.push_back(node->val);
        }
        dfs(node->left, dist, d+1, result);
        dfs(node->right, dist, d+1, result);
    }
    int helper(TreeNode* root, TreeNode* target, int k, vector<int> &result) {
        if (root == NULL) {
            return -1;
        }
        if (root == target) {
            dfs(root, k, 0, result);
            return 1;
        }
        int l = helper(root->left, target, k, result);
        int r = helper(root->right, target, k, result);
        if (l != -1) {
            if (l == k) {
                result.push_back(root->val);
            } else {
                dfs(root->right, k, l+1, result);    
            }
            return l+1;
        }
        if (r != -1) {
            if (r == k) {
                result.push_back(root->val);
            } else {
                dfs(root->left, k, r+1, result);
            }
            return r+1;
        }
        return -1;
    }
};