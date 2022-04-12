// https://leetcode.com/problems/verifying-an-alien-dictionary/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int size = words.size();
        map<char,int> m;
        for(int i = 0; i < order.length(); i++) {
            m[order[i]] = i;
        }
        for (int i = 0; i < size-1; i++) {
            string a = words[i];
            string b = words[i+1];
            int i1 = 0;
            int i2 = 0;
            while(i1 < a.length() && i2 < b.length()) {
                if (m[a[i1]] == m[b[i2]]) {
                    i1++;
                    i2++;
                } else if (m[a[i1]] > m[b[i2]]) {
                    return false;
                } else {
                    break; // order is sorted
                }
            }
            if (i1 < a.length() && i2 >= b.length()) { // a is bigger than b
                return false;
            }
        }
        return true;
    }
};