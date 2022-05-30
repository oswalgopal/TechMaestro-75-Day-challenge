// https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> result;
        if (m[0][0] == 1) {
            m[0][0] = 2;
            helper(m, n, 0, 0, result, "");
        }
        return result;
    }
    void helper(vector<vector<int>> m, int n, int row, int col, vector<string> &result, string path) {
        if (row == n-1 && col == n-1) {
            result.push_back(path);
            return;
        }  
        string dir = "DLRU";
        int dx[] = {1,0,0,-1};
        int dy[] = {0,-1,1,0};
        for (int i = 0; i < 4; i++) {
            int r = row + dx[i];
            int c = col + dy[i];
            if (isValid(r, c, m, n)) {
                m[r][c] = 2; // 2 for visited;
                helper(m, n, r, c, result, path+dir[i]);
                m[r][c] = 1; // 1 for unvisited;
            }
        }
    }
    bool isValid(int row, int col, vector<vector<int>> m, int n) {
        if (row >= 0 && row < n && col >= 0 && col < n && m[row][col] == 1) {
            return true;
        } else {
            return false;
        }
    }
};