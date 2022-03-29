// https://leetcode.com/problems/3sum-closest/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = INT_MAX;
        int minVal = INT_MAX;
        int size = nums.size();
        for (int i = 0; i < size-2; i++) {
            int start = i+1;
            int end = size-1;
            while(start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if (sum == target) {
                    return target;
                } else if (sum > target) {
                    end--;
                } else {
                    start++;
                }
                if (abs(target-sum) < minVal) {
                    minVal = abs(target-sum);
                    result = sum;
                }
            }
        }
        
        return result;
    }
};