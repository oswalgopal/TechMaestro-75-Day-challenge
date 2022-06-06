// https://leetcode.com/problems/gray-code/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        grayCodeHelper(n, result);
        return result;
    }
    void grayCodeHelper(int n, vector<int>& result){
        if (n == 0) {
            result.push_back(0);
            return;
        }
        grayCodeHelper(n-1, result); // calling again for n -1
        int size = result.size(); // getting the size of current
        int mask = 1 << (n-1); // left shifting n bits
        for (int i = size-1; i >= 0; i--) {
            result.push_back(result[i] | mask); // now taking or with all element to add 1 at starting of the number
        }
        // not appending 0 at the start because of no use
        return;
    }
};