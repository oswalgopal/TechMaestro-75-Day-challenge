// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1/

double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double result = 0;
        vector<pair<double, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({1.0*arr[i].value/arr[i].weight, arr[i].weight});
        }
        sort(v.begin(), v.end(), [&](pair<double, int> &a, pair<double, int> &b) {
            return a.first > b.first;
        });
        for (int i = 0; i < n; i++) {
            if (W >= v[i].second) {
                result += (v[i].second * v[i].first);
                W -= v[i].second;
            } else {
                result += (W * v[i].first);
                W = 0;
            }
        }
        return result;
    }