// https://leetcode.com/problems/maximum-product-subarray/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int size = nums.size();
        int maxVal = result;
        int minVal = result;
        for (int i = 1; i < size; i++) {
            if (nums[i] < 0) { // number is -ve so swapping minVal and maxVal for maximum
                swap(maxVal, minVal);
            }
            maxVal = max(nums[i], maxVal * nums[i]);
            minVal = min(nums[i], minVal * nums[i]);
            result = max(result, maxVal);
        }
        return result;
    }
};