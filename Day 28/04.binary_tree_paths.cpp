// https://leetcode.com/problems/binary-tree-paths/
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        helper(root, "", result);
        return result;
    }
    void helper(TreeNode* root, string path, vector<string>& result) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            path += to_string(root->val);
            result.push_back(path);
            return;
        }
        path += to_string(root->val) + "->";
        helper(root->left, path, result);
        helper(root->right, path, result);
    }
};