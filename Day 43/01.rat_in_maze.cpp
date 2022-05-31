// https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/

vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes 
        vector<string> result;
        if (m[0][0] == 1) {
            m[0][0] = 2;
            helper(m, "", n, 0, 0, result);
        }
        return result;
    }
    void helper(vector<vector<int>> m, string s, int n, int i, int j, vector<string> &result) {
        if ((i == n-1) && (j == n-1)) {
            result.push_back(s);
            return;
        }
        // cout << i << " " << j << " " << (n-1) << endl;
        string dir = "DLRU";
        int arr[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
        for (int index = 0; index < 4; index++) {
            int x = i + arr[index][0];
            int y = j + arr[index][1];
            if (x >= 0 && y >= 0 && x < n && y < n && m[x][y] == 1) {
                m[x][y] = 2; // visited
                helper(m, s+dir[index], n, x, y, result);
                m[x][y] = 1; // unvisited
            }
        } 
    }