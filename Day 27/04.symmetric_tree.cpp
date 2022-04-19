// https://leetcode.com/problems/symmetric-tree/
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
    bool isSymmetric(TreeNode* root) {
        if (root== NULL) {
            return true;
        }
        return helper(root->left, root->right);
    }
    bool helper(TreeNode* n1, TreeNode* n2) {
        if (n1 == NULL && n2 == NULL) {
            return true;
        }
        if (n1 == NULL || n2 == NULL) {
            return false;
        }
        if (n1->val != n2->val) {
            return false;
        }
        return helper(n1->left, n2->right) && helper(n1->right, n2->left);
    }
};

// iterative approach
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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        stack<TreeNode*> stk1;
        stk1.push(root->left);
        stack<TreeNode*> stk2;
        stk2.push(root->right);
        while(!stk1.empty() && !stk2.empty()) {
            TreeNode* n1 = stk1.top();
            stk1.pop();
            TreeNode* n2 = stk2.top();
            stk2.pop();
            if (n1 == NULL && n2 == NULL) {
                continue;
            } else if (n1 == NULL || n2 == NULL) {
                return false;
            }
            if (n1->val != n2->val) {
                return false;
            }
            stk1.push(n1->left);
            stk2.push(n2->right);
            stk1.push(n1->right);
            stk2.push(n2->left);
        }
        return true;
     }
};