// https://leetcode.com/problems/maximum-width-of-binary-tree/
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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        unsigned long long int result = 1;
        queue<pair<TreeNode*, unsigned long long int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                pair<TreeNode*, unsigned long long int> t = q.front();
                q.pop();
                if (t.first->left) {
                    q.push({t.first->left, (t.second * 2)});
                }
                if (t.first->right) {
                    q.push({t.first->right, (t.second * 2) + 1});
                }
            }
            if (!q.empty())
                result = max(result, (q.back().second - q.front().second + 1));
        }
        return result;
    }
};