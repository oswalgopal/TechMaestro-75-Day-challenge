// https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int start = 0;
        int end = size-1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            if (nums[mid] == target) {
                return mid;
            }
            // checking the first half sorted
            if (nums[start] <= nums[mid]) {
                if (nums[start] <= target && target <= nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else { // 2nd half sorted
                if (nums[mid] <= target && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};