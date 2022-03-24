// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int,int> m;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            // checking that the 2nd element exist in or not
            int key = target-nums[i];
            if (m.find(key) != m.end()) {
                 result.push_back(m[key]);
                 result.push_back(i);
                return result;
            }
            // adding elements to the map
            m[nums[i]] = i;
        }
        return result;
    }
};