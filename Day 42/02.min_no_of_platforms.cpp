// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int result = 0;
    	vector<int> train(2400, 0);
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	for (int i = 0; i < n; i++) {
    	    train[arr[i]]++;
    	    train[dep[i]+1]--;
    	}
    	int sum = 0;
    	for (int i = 0; i < 2400; i++) {
    	    sum += train[i];
    	    result = max(result, sum);
    	}
    	
    	return result;
    }