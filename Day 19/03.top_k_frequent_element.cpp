// https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        map<int,int> m;
        for (int i: nums) {
            m[i]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        for (auto it: m) {
            pq.push({it.second, it.first});
        }
        while(!pq.empty() && k--) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;
    }
};