// https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        helper(nums, 0, result);
        return result;
    }
    void helper(vector<int> &nums, int index, vector<vector<int>> &result) {
        if (index >= nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);
            helper(nums, index+1, result);
            swap(nums[i], nums[index]);
        }
    }
};