// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long int result = 0;
        long long int mod = 1e9 + 7;
        int m = horizontalCuts.size();
        int n = verticalCuts.size();
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int hd = max(h-horizontalCuts[m-1], horizontalCuts[0]);
        int wd = max(w-verticalCuts[n-1], verticalCuts[0]);
        for (int i = 0; i < m-1; i++) {
            hd = max(hd, (horizontalCuts[i+1]-horizontalCuts[i]));
        }
        for (int i = 0; i < n-1; i++) {
            wd = max(wd, (verticalCuts[i+1]-verticalCuts[i]));
        }
        result = (hd%mod) * (wd%mod);
        result = result % mod;
        return result;
    }
};