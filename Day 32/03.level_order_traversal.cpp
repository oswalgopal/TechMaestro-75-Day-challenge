// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> result;
    vector<vector<int>> levelOrder(TreeNode* root) {
        helper(root, 0);
        return result;
    }
    void helper(TreeNode* node, int d) {
        if (node == NULL){
            return;
        }
        if (result.size() > d) {
            result[d].push_back(node->val);
        } else {
            vector<int> t;
            t.push_back(node->val);
            result.push_back(t);
        }
        helper(node->left, d+1);
        helper(node->right, d+1);
    }
};