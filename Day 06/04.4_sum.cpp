// https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size-3; i++) {
            long long int n1 = nums[i];
            // now its a three sum problem
            for (int j = i + 1; j < size-2; j++) {
                long long int n2 = nums[j];
                // now its two sum problem
                    int start = j+1;
                    int end = size-1;
                    while(start < end) {
                        long long int t = n1 + n2 + nums[start] + nums[end];
                        if (t == target) {
                            vector<int> v;
                            v.push_back(n1);
                            v.push_back(n2);
                            v.push_back(nums[start]);
                            v.push_back(nums[end]);
                            result.push_back(v);
                            while(start+1 < size && nums[start] == nums[start+1]) {
                                start++;
                            }
                            while(end-1 > 0 && nums[end] == nums[end-1]) {
                                end--;
                            }
                            start++;
                            end--;
                        } else if (t > target) {
                            end--;
                        } else {
                            start++;
                        }
                    }
                while(j < size-2 && nums[j] == nums[j+1]) {
                    j++;
                }
            }
            while(i < size-3 && nums[i] == nums[i+1]) {
                i++;
            }
        }
        
        return result;
    }
};