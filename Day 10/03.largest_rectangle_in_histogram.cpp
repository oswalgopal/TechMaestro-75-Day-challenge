// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        int size = heights.size();
        stack<pair<int,int>> stk;
        vector<int> NSL(size, 0);
        vector<int> NSR(size, 0);
        
        for (int i = 0; i < size; i++) {
            if (stk.empty()) {
                NSL[i] = -1;
            } else if (!stk.empty() && stk.top().first >= heights[i]) {
                while(!stk.empty() && stk.top().first >= heights[i]) {
                    stk.pop();
                }
                if (stk.empty()) {
                    NSL[i] = -1;
                } else {
                    NSL[i] = i - stk.top().second;
                }
            } else {
                NSL[i] = i - stk.top().second;
            }
            stk.push({heights[i], i});
        }
        while(!stk.empty()) {
            stk.pop();
        }
        for (int i = size-1; i >= 0; i--) {
            if (stk.empty()) {
                NSR[i] = -1;
            } else if (!stk.empty() && stk.top().first >= heights[i]) {
                while(!stk.empty() && stk.top().first >= heights[i]) {
                    stk.pop();
                }
                if (stk.empty()) {
                    NSR[i] = -1;
                } else {
                    NSR[i] = stk.top().second - i;
                }
            } else {
                NSR[i] = stk.top().second - i;
            }
            stk.push({heights[i], i});
        }
        
        for (int i = 0; i < size; i++) {
            int ans = 0;
            if (NSL[i] != -1) {
                ans += (heights[i] * (NSL[i]-1));
            } else {
                ans += (heights[i] * (i));
            }
            if (NSR[i] != -1) {
                ans += (heights[i] * (NSR[i]-1));
            } else {
                ans += (heights[i] * (size-1-i));
            }
            ans += heights[i];
            result = max(ans, result);
        }
        
        return result;
    }
};