// https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int result = 0;
        int start = 0; // window start
        int size = s.length();
        for (int i = 0 ; i < size; i++) {
            count[s[i]-'A']++;
            int maxF = 0;
            for (int j = 0; j < 26; j++) {
                maxF = max(maxF, count[j]);
            }
            cout << maxF << " ";
            // check the window
            cout << i-start+1-maxF << endl;
            if (i-start+1-maxF > k) {
                // remove the element from the window
                count[s[start]-'A']--;
                cout << s[start] << endl;
                // moving the window
                start++;
                
            }
            result = max(result, i-start+1);
        }
        
        return result;
    }
};