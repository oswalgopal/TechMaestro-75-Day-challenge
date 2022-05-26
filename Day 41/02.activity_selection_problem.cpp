// https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1

int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        int result = 0;
        vector<pair<int,int>> act;
        // mapped the two arrays into 1 array
        for (int i = 0; i < n; i++) {
            act.push_back({start[i], end[i]});
        }
        
        // sort the act array / vector
        sort(act.begin(), act.end(), [&] (pair<int,int> a, pair<int,int> b) {
           return a.second < b.second; 
        });
        
        // select the activities on the basis of start and end time
        result++; // first activity selected
        int prevEndTime = act[0].second;
        for (int i = 1; i < n; i++) {
            // how to pick the next
            // 1. start time of next should be greater than or equal to end time of last one
            if (prevEndTime < act[i].first) {
                result++;
                prevEndTime = act[i].second;
            }
        }
        
        return result;
    }