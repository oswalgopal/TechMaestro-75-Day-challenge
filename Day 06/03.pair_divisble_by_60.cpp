// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int result = 0;
        map<int,int> m;
        int size = time.size();
        for (int i = 0; i < size; i++) {
            int n = time[i]%60;
            if (n == 0) {
                result+= m[0];
            } else {
                result += m[60-n];
            }
            m[n]++;
        }
        return result;
    }
};