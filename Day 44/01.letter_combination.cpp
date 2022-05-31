// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        int size = digits.size();
        if (size == 0) {
            return result;
        }
        result.push_back("");
        string arr[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (char c: digits) {
            int num = c-'0';
            vector<string> t;
            for (string s: result) {
                for (char c: arr[num]) {
                    t.push_back(s+c);
                }
            }
            result.swap(t);
        }
        return result;
    }
};