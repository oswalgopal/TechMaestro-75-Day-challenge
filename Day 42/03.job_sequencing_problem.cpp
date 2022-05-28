// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int> result;
        sort(arr, arr+n, [&](Job &a, Job &b) {
           return a.profit > b.profit; 
        });
        int count =0;
        int maxProfit = 0;
        vector<int> slot(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = min(n, arr[i].dead)-1; j >= 0; j--) {
                if (slot[j] == 0) { // empty slot
                    slot[j] = 1;
                    count++;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }
        result.push_back(count);
        result.push_back(maxProfit);
        return result;
    } 