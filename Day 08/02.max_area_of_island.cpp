// https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int t = 0;
                helper(grid, i, j, &t);
                result = max(result, t);
            }
        }
        return result;
    }
    void helper(vector<vector<int>>& grid, int i, int j, int *t) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
            return;
        }
        *t = *t + 1;
        grid[i][j] = 0;
        helper(grid, i+1, j, t);
        helper(grid, i-1, j, t);
        helper(grid, i, j+1, t);
        helper(grid, i, j-1, t);
    }
};