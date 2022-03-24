// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int index = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] != 0) {
                nums[index] = nums[i];
                index++;
            }
        }
        while(index < size) {
            nums[index] = 0;
            index++;
        }
    }
};