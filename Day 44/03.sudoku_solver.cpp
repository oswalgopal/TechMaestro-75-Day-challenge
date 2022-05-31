// https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1/
bool check(int grid[N][N], int row, int col, int val) {
        // check that col
        for (int i = 0; i < N; i++) {
            if (grid[row][i] == val) {
                return false;
            }
        }
        // check that row
        for (int i = 0; i < N; i++) {
            if (grid[i][col] == val) {
                return false;
            }
        }
        int r = row / 3;
        int c = col / 3;
        for (int i = r * 3; i < ((3 * r) + 3); i++) {
            for (int j = c * 3; j < ((3 * c) + 3); j++) {
                if (grid[i][j] == val) {
                    return false;
                }
            }    
        }
        return true;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 0) {
                    for (int c = 1; c <= 9; c++) {
                        if (check(grid, i, j, c)) {
                            grid[i][j] = c;
                            if (SolveSudoku(grid)) {
                                return true;
                            } else {
                                grid[i][j] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        int n = N;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j] << " ";
            }
        }
    }