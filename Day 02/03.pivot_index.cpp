// https://leetcode.com/problems/find-pivot-index/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefixSum(size, 0);
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += nums[i];
            prefixSum[i] = sum;
        }
        for (int i = 0; i < size; i++) {
            int s1 = 0;
            int s2 = 0;
            if (i > 0) {
                s1 = prefixSum[i-1];
            }
            s2 = sum - prefixSum[i];
            if (s1 == s2) {
                return i;
            }
        }
        
        
        return -1;
    }
};