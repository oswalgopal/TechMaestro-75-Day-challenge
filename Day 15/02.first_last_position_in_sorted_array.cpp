// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int size = nums.size();
        int start = 0;
        int end = size-1;
        bool found = false;
        while(start <= end) {
            int mid = start + (end-start)/2;
            if (nums[mid] == target) {
                end = mid-1;
                found = true;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        if (!found) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        result.push_back(start);
        start = 0;
        end = size-1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            if (nums[mid] == target) {
                start = mid+1;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        result.push_back(end);
        return result;
    }
};