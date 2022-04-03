// https://leetcode.com/problems/first-missing-positive/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n+1;
            }
        }
        for (int i = 0; i < n; i++) {
            int t = abs(nums[i]);
            if (t == n+1) {
                continue;
            }
            if (nums[t-1] > 0) {
                nums[t-1] *= -1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                return i+1;
            }
        }
        
        return n+1;
    }
};