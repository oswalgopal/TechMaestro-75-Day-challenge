// https://leetcode.com/problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {
            return true;
        }
        int maxJump = 0;
        for (int i = 0; i < size; i++) {
            if (maxJump < i) {
                return false;
            }
            maxJump = max(maxJump, i+ nums[i]);
        }
        if (maxJump >= size-1) {
            return true;
        }
        
        return false;
    }
};