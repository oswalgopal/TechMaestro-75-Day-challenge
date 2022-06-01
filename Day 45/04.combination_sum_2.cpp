// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        vector<int> t;
        helper(candidates, target, 0, t, result, 0);
        return result;
    }
    void helper(vector<int> &candidates, int target, int sum, vector<int> set, vector<vector<int>> &result, int index) {
        if (target == sum) {
            result.push_back(set);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (sum + candidates[i] <= target) {
                set.push_back(candidates[i]);
                helper(candidates, target, sum+candidates[i], set, result, i+1);
                set.pop_back();
                while(i+1 < candidates.size() && candidates[i] == candidates[i+1]) {
                    i++;
                }
            }
        }
    }
};