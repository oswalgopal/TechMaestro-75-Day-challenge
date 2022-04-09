// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();
        if (s1 < s2) { // nums1 must be greater
            return findMedianSortedArrays(nums2, nums1);
        }
        
        // binary search
        int start = 0;
        int end = s2 * 2;
        while(start <= end) {
            int mid2 = start + (end-start)/2;
            int mid1 = s1 + s2 - mid2;   
            double l1 = mid1 == 0 ? INT_MIN : nums1[(mid1-1)/2];
            double l2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
            double r1 = (mid1 == s1 * 2) ? INT_MAX : nums1[(mid1)/2];
            double r2 = (mid2 == s2 * 2) ? INT_MAX : nums2[(mid2)/2];
            if (l1 > r2) {
                start = mid2 + 1;
            } else if (l2 > r1) {
                end = mid2 - 1;
            } else {
                return (max(l1,l2) + min(r1, r2)) / 2;
            }
        }
        
        return -1;
    }
};