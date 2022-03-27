// https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // step 1:- get first decreasing from right
        // step 2:- find the increasing for that 
        // step 3:- swap both and reverse all number
        int size = nums.size();
        int i = size-1;
        while(i > 0 && nums[i-1] >= nums[i]) {
            i--;
        }
        int index = i-1;
        if (i > 0) {
            // got the increasing for nums[index]
            while(i < size && nums[i] > nums[index]) {
                i++;
            }
            // swapping both
            int t = nums[index];
            nums[index] = nums[i-1];
            nums[i-1] = t;
        }
        // reverse the values
        int start = index+1;
        int end = size-1;
        while(start < end) {
            int t = nums[start];
            nums[start] = nums[end];
            nums[end] = t;
            start++;
            end--;
        }
    }
};