// https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/

// Backtracking is an algorithmic paradigm that tries different solutions until finds a solution that “works”.

#include<iostream>
#include<vector>
using namespace std;

int n = 8;
int moves[8][2] = {{2, 1}, {1, 2}, {2, -1}, {-1, 2}, {-2, 1}, {1, -2}, {-1, -2}, {-2, -1}};

bool solveUtil(vector<vector<int> > &board, int i, int j, int move) {
    cout << "called util" << i << " " << j << " " << move << endl;
    if (move == (n*n)) {
        return true;
    }
    for (int index = 0; index < 8; index++) {
        int x = i + moves[index][0];
        int y = j + moves[index][1];
        if (x >= 0 && x < n && y >= 0 && y < n && (board[x][y] == -1)) {
            board[x][y] = move;
            if (solveUtil(board, x, y, move + 1)) {
                return true;
            } else {
                board[x][y] = -1; // backtrack
            }
        }
    }
    return false;
}

void solve() {
    vector<vector<int> > board(n, vector<int>(n, -1));
    board[0][0] = 0;
    for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            } cout << endl;
        }
    if (solveUtil(board, 0, 0, 1) == 0) {
        cout << "Solution doesnot exist";
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            } cout << endl;
        }
    }
}

int main() {
    
    solve();
    return 0;
}