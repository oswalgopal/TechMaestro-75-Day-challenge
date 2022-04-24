// https://leetcode.com/problems/binary-search-tree-iterator/

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
class BSTIterator {
public:
    TreeNode* node = new TreeNode(-1);
    BSTIterator(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* temp = root;
        TreeNode* curr = node;
        while(temp != NULL || !stk.empty()) {
            while(temp != NULL) {
                stk.push(temp);
                temp = temp->left;
            }
            temp = stk.top();
            stk.pop();
            curr->right = new TreeNode(temp->val);
            curr = curr->right;
            temp = temp->right;
        }
        curr = node;
    }
    
    int next() {
        if (!node) {
            return -1;
        }
        node = node->right;
        if (node != NULL) {
            return node->val;
        }
        return -1;
    }
    
    bool hasNext() {
        if (!node) {
            return false;
        }
        return node->right != NULL;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */