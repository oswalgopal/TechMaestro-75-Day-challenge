// https://leetcode.com/problems/next-greater-element-i/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int size = nums2.size();
        vector<int> result;
        stack<int> stk;
        map<int,int> m;
        for (int i = size-1; i >= 0; i--) {
            if (stk.empty()) {
                m[nums2[i]] = -1;
            } else if (!stk.empty() && stk.top() <= nums2[i]) {
                while (!stk.empty() && stk.top() <= nums2[i]) {
                    stk.pop();
                }
                if (stk.empty()) {
                    m[nums2[i]] = -1;
                } else {
                    m[nums2[i]] = stk.top();    
                }
            } else {
                m[nums2[i]] = stk.top();
            }
            stk.push(nums2[i]);
        }
        for (int i: nums1) {
            result.push_back(m[i]);
        }
        
        return result;
    }
};