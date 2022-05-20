// https://leetcode.com/problems/the-skyline-problem/
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> result;
        vector<pair<int,int>> t;
        for (vector<int> &b: buildings) {
            t.push_back({b[0], -b[2]}); // start point of building
            t.push_back({b[1], b[2]}); // start point of building
        }
        sort(t.begin(), t.end());
        multiset<int> m; // to maintain current max height
        m.insert(0); // intial height is 0
        int curr = 0;
        int pre = 0;
        for (pair<int,int> i: t) {
            // if we encounter start of the building
            if (i.second < 0) {
                m.insert(-i.second);
            } else {
                m.erase(m.find(i.second)); // remove the end of the building
            }
            curr = *(m.rbegin()); // last element of set i.e max element
            // if max value changes then it must be a skyline so add it to result
            if (curr != pre) {
                vector<int> temp;
                temp.push_back(i.first);
                temp.push_back(curr);
                result.push_back(temp);
                pre = curr;
            }
        }
        
        return result;
    }
};