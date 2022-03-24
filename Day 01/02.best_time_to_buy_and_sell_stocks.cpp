// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        // to store the min value in past days
        int minVal = INT_MAX;
        int size = prices.size();
        for (int i = 0; i < size; i++) {
            if (minVal > prices[i]) {
                minVal = prices[i];
            }
            // updating the result if getting more profit
            result = max(result, (prices[i]-minVal));
        }
        return result;
    }
};