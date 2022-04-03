// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
class Solution {
public:
    // bought state, transaction, position
    vector<vector<vector<int>>> dp;
    int helper(vector<int>& prices, int pos, int transaction, bool boughtState) {
        // base case
        if (pos >= prices.size() || transaction == 0) {
            return 0;
        }
        if (dp[boughtState][transaction][pos] != -1) {
            return dp[boughtState][transaction][pos];
        }
        int result = helper(prices, pos+1, transaction, boughtState); // calling for skip
        if (boughtState) { // we can only sell
            result = max(result,(helper(prices, pos+1, transaction-1, false)+prices[pos]));
        } else { // we can only buy
            result = max(result, (helper(prices, pos+1, transaction, true)-prices[pos]));
        }
        dp[boughtState][transaction][pos] = result;
        return result;
    }
    int maxProfit(vector<int>& prices) {
        int result = 0;
        // 2 because at most two allowed
        // 3 transactions => buy, sell, skip
        dp.resize(2, vector<vector<int>>(3, vector<int>(prices.size(), -1)));
        result = helper(prices, 0, 2, false);
        return result;
    }
};