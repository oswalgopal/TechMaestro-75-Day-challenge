// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    int getHeight(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int l = getHeight(node->left);
        int r = getHeight(node->right);
        return max(l, r) + 1;
    }
    void getNodes(TreeNode* node, vector<int> &t, int i, int direction) {
        if (node == NULL) {
            return;
        }
        if (i == 0) {
            t.push_back(node->val);
        }
        if (direction == 0) {
            getNodes(node->left, t, i-1, direction);
            getNodes(node->right, t, i-1, direction);
        } else {
            getNodes(node->right, t, i-1, direction);
            getNodes(node->left, t, i-1, direction);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int h = getHeight(root);
        
        for (int i = 0; i < h; i++) {
            vector<int> t;
            getNodes(root, t, i, i%2);
            result.push_back(t);
        }
        
        return result;
    }
};