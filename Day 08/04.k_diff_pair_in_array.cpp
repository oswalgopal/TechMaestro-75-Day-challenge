// https://leetcode.com/problems/k-diff-pairs-in-an-array/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int result = 0;
        map<int,int> m;
        for (int i: nums) {
            m[i]++;
        }
        for (auto it: m) {
            if (k == 0) {
                if (it.second >= 2) {
                    result++;
                }
            } else {
                if (m.find(it.first-k) != m.end()) {
                    result++;
                }
            }
        }
        return result;
    }
};