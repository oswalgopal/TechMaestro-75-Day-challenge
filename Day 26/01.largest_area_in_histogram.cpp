// https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        stack<pair<int,int>> stk;
        int size = heights.size();
        vector<int> NSL(size, -1);
        vector<int> NSR(size, -1);
        for (int i = size-1; i >= 0; i--) {
            if (stk.empty()) {
                NSR[i] = -1;
            } else if (!stk.empty() && stk.top().first >= heights[i]) {
                while (!stk.empty() && stk.top().first >= heights[i]) {
                    stk.pop();
                }
                if (stk.empty()) {
                    NSR[i] = -1;
                } else {
                    NSR[i] = (stk.top().second-i);
                }
            } else {
                NSR[i] = (stk.top().second-i);
            }
            stk.push({heights[i], i});
        }
        while(!stk.empty()) {
            stk.pop();
        }
        for (int i = 0; i < size; i++) {
            if (stk.empty()) {
                NSL[i] = -1;
            } else if (!stk.empty() && stk.top().first >= heights[i]) {
                while (!stk.empty() && stk.top().first >= heights[i]) {
                    stk.pop();
                }
                if (stk.empty()) {
                    NSL[i] = -1;
                } else {
                    NSL[i] = (i -stk.top().second);
                }
            } else {
                NSL[i] = (i-stk.top().second);
            }
            stk.push({heights[i], i});
        }
        
        for (int i = 0; i < size; i++) {
            // cout << heights[i] << " " <<  NSL[i] << " " << NSR[i] << endl;
            int area = 0;
            if (NSL[i] == -1) {
                area += (heights[i] * (i+1));
            } else {
                area += (heights[i] * (NSL[i]));
            }
            if (NSR[i] == -1) {
                area += (heights[i] * (size-i));
            } else {
                area += (heights[i] * (NSR[i]));
            }
            area-=heights[i];
            result = max(area, result);
        }
        
        
        return result;
    }
};