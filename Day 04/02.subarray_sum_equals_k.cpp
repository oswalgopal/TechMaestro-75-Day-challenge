// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        map<int,int> m;
        int size = nums.size();
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += nums[i];
            if (sum == k) {
                result++;
            }
            if (m[sum-k]) {
                result += m[sum-k];
            }
            m[sum]++;
        }
        
        return result;
    }
};