// https://leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:
    int numTrees(int n) {
        vector<int> catlan(n+1, 0);
        catlan[0] = catlan[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                catlan[i] += (catlan[j] * catlan[i-1-j]);
            }
        }
        return catlan[n];
    }
};