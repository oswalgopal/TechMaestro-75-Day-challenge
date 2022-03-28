// https://leetcode.com/problems/word-search/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (helper(board, word, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool helper(vector<vector<char>> &board, string& word, int i, int j) {
        if (word.size() == 0) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return false;
        }
        if (board[i][j] != word[0]) {
            return false;
        }
        string t = word.substr(1);
        char c = board[i][j];
        board[i][j] = '*';
        bool res =  helper(board, t, i+1, j) || helper(board, t, i, j+1) || helper(board, t, i-1, j) || helper(board, t, i, j-1);
        board[i][j] = c;
        return res;
    }
};