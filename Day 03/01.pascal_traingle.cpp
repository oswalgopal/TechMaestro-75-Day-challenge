// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> t;
        t.push_back(1);
        if (numRows >= 1) {
            result.push_back(t);
        }
        if (numRows >= 2) {
            t.push_back(1);
            result.push_back(t);
        }
        for (int i = 2; i < numRows; i++) {
            vector<int> k;
            k.push_back(1);
            for (int j = 1; j < i; j++) {
                int n = result[i-1][j-1] + result[i-1][j];
                k.push_back(n);
            }
            k.push_back(1);
            result.push_back(k);
        }
        
        return result;
    }
};