// https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int size = arr.size();
        int start = 0;
        int end = size-1;
        while(start < end) {
            int mid = start + (end-start)/2;
            if (arr[mid-1] > arr[mid]) {
                end = mid;
            } else if (arr[mid] < arr[mid+1]) {
                start = mid + 1;
            } else {
                return mid;
            }
        }
        return start;
    }
};