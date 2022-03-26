// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (index == 0 || nums[index-1] != nums[i]) {
                nums[index] = nums[i];
                nums[index++];
            }
        }
        return index;
    }
};