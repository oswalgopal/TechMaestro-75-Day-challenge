// https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = 0;
        int count = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (count == 0) {
                result = nums[i];
            }
            if (nums[i] == result) {
                count++;
            } else {
                count--;
            }
        }
        return result;
    }
};