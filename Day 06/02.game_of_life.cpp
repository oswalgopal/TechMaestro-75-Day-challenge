// https://leetcode.com/problems/3sum-closest/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count = 0;
                for (int x=max(i-1, 0); x<min(i+2, m); x++) {
                    for (int y=max(j-1, 0); y<min(j+2, n); y++) {
                        count += board[x][y] & 1;
                    }    
                }
                if (count == 3 || count - board[i][j] == 3) {
                    board[i][j] |= 2;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = board[i][j] >> 1;
            }
        }
    }
};