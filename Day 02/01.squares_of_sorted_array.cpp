// https://leetcode.com/problems/squares-of-a-sorted-array/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, 0);
        int start = 0;
        int end = size-1;
        int index = size-1;
        while(start <= end) {
            int n1 = nums[start] * nums[start];
            int n2 = nums[end] * nums[end];
            if (n1 > n2) {
                result[index] = n1;
                start++;
            } else {
                result[index] = n2;
                end--;
            }
            index--;
        }
        return result;
    }
};