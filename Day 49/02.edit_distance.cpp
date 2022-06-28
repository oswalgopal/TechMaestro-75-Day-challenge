// https://leetcode.com/problems/edit-distance/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return helper(word1, word2, m, n, dp);
    }
    int helper(string word1, string word2, int m, int n, vector<vector<int>> &dp) {
        if (m == 0) {
            return n; // need to remove n characters from word2
        }
        if (n == 0) {
            return m; // need to add m characters to word1
        }
        if (dp[m][n] != -1) {
            return dp[m][n]; // memoization
        }
        if (word1[m-1] == word2[n-1]) { // same character so do nothing
            return dp[m][n] = helper(word1, word2, m-1, n-1, dp);
        }
        // check min value from all cases
        int ans = INT_MAX;
        ans = min(ans, helper(word1, word2, m-1, n-1, dp)); // replace
        ans = min(ans, helper(word1, word2, m-1, n, dp)); // delete 
        ans = min(ans, helper(word1, word2, m, n-1, dp)); // addition
        return dp[m][n] = 1 + ans;
    }
};