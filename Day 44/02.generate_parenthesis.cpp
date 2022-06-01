// https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        helper(n, result, 0, 0, "");
        return result;
    }
    void helper(int n, vector<string> &result, int open, int close, string temp) {
        if (temp.length() == 2 * n) {
            result.push_back(temp);
            return;
        }
        if (open < n) {
            helper(n, result, open+1, close, temp + "(");
        }
        if (close < open) {
            helper(n, result, open, close+1, temp + ")");
        }
    }
};