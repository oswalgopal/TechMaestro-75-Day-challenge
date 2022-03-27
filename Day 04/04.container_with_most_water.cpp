// https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int size = height.size();
        int start = 0;
        int end = size-1;
        int width = size-1;
        while(start < end) {
            int l = min(height[start], height[end]);
            int area = (l * width);
            result = max(area, result);
            width--;
            // moving away from the shorter side
            if (height[start] < height[end]) {
                start++;
            } else {
                end--;
            }
        }
        
        return result;
    }
};