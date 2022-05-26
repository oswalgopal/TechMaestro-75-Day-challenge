// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#

int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        int result = 0;
        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({start[i], end[i]});
        }
        sort(v.begin(), v.end(), [&](pair<int,int> &a, pair<int,int> &b) {
           return a.second < b.second; 
        });
        pair<int,int> last = v[0];
        result = 1;
        for (int i = 1; i < n; i++) {
            if (last.second < v[i].first) {
                result++;
                last = v[i];
            }
        }
        return result;
    }