// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
       for (int i = 0; i <= n; i++) {
           for (int j = 0; j <= W; j++) {
               if (i == 0 || j == 0) {
                   dp[i][j] = 0;
               }
           }
       }
       
       for (int i = 1; i <= n; i++) {
           for (int j = 1; j <= W; j++) {
               if (wt[i-1] <= j) {
                   dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j-wt[i-1]]);
               } else {
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       
       return dp[n][W];
    }