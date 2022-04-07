// https://leetcode.com/problems/find-peak-element/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        int start = 0;
        int end = size-1;
        while(start < end) {
            int mid = start + (end-start)/2;
            if (mid > 0 && nums[mid] < nums[mid-1]) {
                end = mid-1;
            } else if (mid+1 < size && nums[mid+1] > nums[mid]) {
                start = mid + 1;
            } else {
                return mid;
            }
        }
        return start;
    }
};