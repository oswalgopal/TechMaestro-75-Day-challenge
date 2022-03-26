// https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i = 0; i < size-2; i++) {
            int start = i + 1;
            int end = size-1;
            while(start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if (sum == 0) {
                    vector<int> t;
                    t.push_back(nums[i]);
                    t.push_back(nums[start]);
                    t.push_back(nums[end]);
                    result.push_back(t);
                    while(start+1 < end && nums[start] == nums[start+1]) {
                       start++;
                    }
                    while(end > start && nums[end] == nums[end-1]) {
                       end--;
                    }
                    start++;
                    end--;
                } else if (sum > 0) {
                    end--;
                } else {
                    start++;
                }
            }
            while(i+1 < size && nums[i] == nums[i+1]) {
                i++;
            }
        }
        
        return result;
    }
};