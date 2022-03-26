// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        for (vector<int> i: intervals) {
            if (result.empty()) {
                result.push_back(i);
            } else if (result.back()[1] >= i[0]) {
                result.back()[1] = max(i[1], result.back()[1]);
            } else {
                result.push_back(i);
            }
        }
        
        return result;
    }
};