// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int result = 0;
        int size = nums.size();
        vector<vector<int>> dp(size+1, vector<int>(size, -1));
        int t = helper(nums, 0, -1, dp);
        // cout << t << endl;
        return t;
    }
    int helper(vector<int> &nums, int index, int prev, vector<vector<int>> &dp) {
        if (index >= nums.size()) {
            return 0;
        }
        if (prev != -1 && dp[prev][index] != -1) {
            return dp[prev][index];
        }
        int incl = 0;
        int nonincl = helper(nums, index+1, prev, dp);
        if (prev == -1 || nums[prev] < nums[index]) {
            incl = 1 + helper(nums, index+1, index, dp);
        }
        if (prev == -1) {
            return max(incl, nonincl);    
        } else {
            return dp[prev][index] = max(incl, nonincl);
        }
        
    }
};

