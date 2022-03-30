// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        vector<int> t;
        helper(candidates, result, 0, t, 0, target);
        
        return result;
    }
    void helper(vector<int> &candidates, vector<vector<int>>& result, int index, vector<int> t, int sum, int target) {
        if (sum == target) {
            result.push_back(t);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] <= target-sum) {
                t.push_back(candidates[i]);
                helper(candidates, result, i, t, sum+candidates[i], target);
                t.pop_back();
            } else {
                break;
            }
        }
    }
};