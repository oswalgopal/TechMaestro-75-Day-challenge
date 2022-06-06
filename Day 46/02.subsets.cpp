// https://leetcode.com/problems/subsets/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        helper(nums, temp, result, 0);
        return result;
    }
    void helper(vector<int> &nums, vector<int> temp, vector<vector<int>> &result, int index) {
        result.push_back(temp);
        for (int i = index; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            helper(nums, temp, result, i+1);
            temp.pop_back();
        }
    }
};