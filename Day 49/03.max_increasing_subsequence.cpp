// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1#

int helper(int arr[], int n, int i, int prev, vector<vector<int>> &dp) {
	    if (i == n) {
	        return 0;
	    }
	    if (dp[i][prev+1] != -1) {
	        return dp[i][prev+1];
	    }
	    int incl = 0;
	    if (prev == -1 || (arr[i] > arr[prev])) {
	        incl = arr[i] + helper(arr, n, i+1, i, dp);
	    }
	    int notincl = helper(arr, n, i+1, prev, dp);
	    return dp[i][prev+1] = max(incl, notincl);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>> dp(n, vector<int>(n+1, -1));
	    int result = helper(arr, n, 0, -1, dp);
	    return result;
	}  
