// https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        int size = nums.size();
        
        for (int i = 0; i < size; i++) {
            int t = nums[abs(nums[i])-1];
            if (t < 0) {
                result.push_back(abs(nums[i]));
            } else {
                nums[abs(nums[i])-1] *= -1;
            }
        }
        
        return result;
    }
};