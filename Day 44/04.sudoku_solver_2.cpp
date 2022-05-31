// https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
    bool helper(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (int c = '1'; c <= '9'; c++) {
                        if (isValid(i, j, board, c)) {
                            board[i][j] = c;
                            if (helper(board)) {
                                return true;
                            } else {
                                board[i][j] = '.'; // backtrack    
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(int row, int col, vector<vector<char>> board, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c) {
                return false;
            }
            if (board[row][i] == c) {
                return false;
            }
            int r = 3 * (row/3); // bring to the current row of 9 box
            int co = 3 * (col/3); // bring to the current col of 9 box
            if (board[r + (i/3)][co+(i%3)] == c) {
                return false;
            }
        }
        return true;
    }
};