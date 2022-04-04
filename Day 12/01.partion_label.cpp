// https://leetcode.com/problems/partition-labels/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        vector<int> arr(26, 0);
        int size = s.length();
        for (int i = 0; i < size; i++) {
            arr[s[i]-'a'] = i;
        }
        int maxVal = INT_MIN;
        int last = 0;
        for (int i = 0; i < size; i++) {
            if (maxVal == i) {
                result.push_back(i-last+1);
                last = i+1;
            }
            maxVal = max(maxVal, arr[s[i]-'a']);
        }
        
        return result;
    }
};