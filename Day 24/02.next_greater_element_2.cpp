// https://leetcode.com/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size);
        stack<int> stk;
        for (int i = size-1; i >= 0; i--) {
            stk.push(nums[i]);
        }
        for (int i = size-1; i >= 0; i--) {
            if (stk.empty()) {
                result[i] = -1;
            } else if (!stk.empty() && stk.top() <= nums[i]) {
                while (!stk.empty() && stk.top() <= nums[i]) {
                    stk.pop();
                }
                if (stk.empty()) {
                    result[i] = -1;
                } else {
                    result[i] = stk.top();
                }
            } else {
                result[i] = stk.top();
            }
            stk.push(nums[i]);
        }
        
        
        return result;
    }
};