// https://leetcode.com/problems/sliding-window-maximum/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int size = nums.size();
        deque<int> dq; // maintain the decreasing order
        for (int i = 0; i < size; i++) {
            // remove the out of range elements
            if (!dq.empty() && dq.front() <= i-k) {
                dq.pop_front();
            }
            // remove the smaller elements
            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i); // adding the element into dequeue
            
            // get the max
            if (i >= k-1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};