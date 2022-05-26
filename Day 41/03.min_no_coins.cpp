// https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1/#
vector<int> minPartition(int N)
    {
        // code here
        vector<int> result;
        int arr[10] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        for (int i = 0; i < 10; i++) {
            if (N >= arr[i]) {
                int count = N/arr[i];
                while(count--) {
                    N -= arr[i];
                    result.push_back(arr[i]);
                }
            }
        }
        return result;
    }