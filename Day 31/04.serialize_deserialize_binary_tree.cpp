// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "#";
        }
        string left = serialize(root->left);
        string right = serialize(root->right);
        return to_string(root->val) + "," + left + "," + right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return helper(data);
    }
    TreeNode* helper(string& data) {
        if (data.length() == 0) {
            return NULL;
        }
        if (data[0] == '#') {
            if(data.size() > 1) {
                data = data.substr(2);
            }
            return NULL;
        }
        int i = data.find(',');
        TreeNode* node = new TreeNode(stoi(data.substr(0, i)));
        data = data.substr(i+1);
        node->left = helper(data);
        node->right = helper(data);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));