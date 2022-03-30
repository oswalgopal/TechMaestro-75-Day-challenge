// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int size = cardPoints.size();
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        int result = sum;
        int rSum = 0;
        for (int i = 0; i < k; i++) {
            sum -= cardPoints[k-1-i];
            rSum += cardPoints[size-1-i];
            result = max(result, sum+rSum);
        }
        return result;
    }
};