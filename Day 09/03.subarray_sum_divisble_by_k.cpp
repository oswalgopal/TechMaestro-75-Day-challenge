// https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int result = 0;
        map<int,int> m;
        m[0] = 1; // 0 is always divisible
        int sum = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            sum = (sum + nums[i]) % k;
            if (sum < 0) {
                sum += k; // for negative values
            }
            result += m[sum]; // check that do the sum of this mod value exist or not
            m[sum]++; // add the curr sum mod 
        }
        return result;
    }
};