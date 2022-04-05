// https://leetcode.com/problems/subarrays-with-k-different-integers/
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
    int atMostK(vector<int>& nums, int k) {
        int i = 0, result = 0;
        unordered_map<int, int> count;
        for (int j = 0; j < nums.size(); ++j) {
            if (!count[nums[j]]++) { 
                k--;
            }
            while (k < 0) {
                if (!--count[nums[i]])  {
                    k++;
                }
                i++;
            }
            result += j - i + 1;
        }
        return result;
    }
};