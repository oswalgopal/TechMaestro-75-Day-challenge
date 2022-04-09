// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
class Solution {
public:
    bool verify(vector<int>& nums, int maxOperation, int mid) {
        int c = 0;
        for (int i: nums) {
            c += (i-1)/mid;
        }
        if (c <= maxOperation) {
            return true;
        }
        
        return false;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int result = 0;
        int maxVal = INT_MIN;
        for (int i: nums) {
            maxVal = max(maxVal, i);
        }
        int start = 1;
        int end = maxVal;
        while(start < end) {
            int mid = start + (end-start)/2;
            if (verify(nums, maxOperations, mid)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        result = start;
        
        return result;
    }
};