// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return helper(preorder, postorder, 0, preorder.size()-1, 0, postorder.size()-1);
    }
    TreeNode* helper(vector<int> preorder, vector<int> postorder, int pre_start, int pre_end, int post_start, int post_end) {
        if (pre_start > pre_end || post_start > post_end) {
            return NULL;
        }
        TreeNode* t = new TreeNode(preorder[pre_start]);
        if (pre_start == pre_end) {
            return t;
        }
        int index = post_start;
        int val = preorder[pre_start+1];
        while (postorder[index] != val && index < post_end) {
            index++;
        }
        t->left = helper(preorder, postorder, pre_start+1, pre_start+index+1-post_start, post_start, index);
        t->right = helper(preorder, postorder, pre_start+index+1-post_start+1, pre_end, index+1, post_end);
        
        return t;
    }
};