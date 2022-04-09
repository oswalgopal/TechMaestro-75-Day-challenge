// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
class Solution {
public:
    bool checkVal(vector<int>& weights, int days, int val) {
        int size = weights.size();
        int s = 0;
        int c = 0;
        for (int i = 0; i < size; i++) {
            if (weights[i] > val) {
                return false;
            }
            if (s + weights[i] <= val) {
                s += weights[i];
            } else {
                s = 0;
                c++;
                s += weights[i];
            }
        }
        if (s >= 0) {
            c++;
        }
        return c <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int result = 0;
        int minVal = INT_MAX;
        int sum = 0;
        int size = weights.size();
        for (int i: weights) {
            sum += i;
            minVal = min(minVal, i);
        }
        int start = minVal;
        int end = sum;
        while(start < end) {
            int mid = start + (end-start) / 2;
            if (checkVal(weights, days, mid)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        
        return start;
    }
};