// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int minVal = INT_MAX;
        int size = prices.size();
        for (int i = 0; i < size; i++) {
            if (minVal > prices[i]) {
                minVal = prices[i];
            } 
            if (prices[i] > minVal) {
                result += (prices[i]-minVal);
                minVal = prices[i];
            }
        }
        return result;
    }
};