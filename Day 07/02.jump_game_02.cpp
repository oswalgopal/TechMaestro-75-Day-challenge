// https://leetcode.com/problems/jump-game-ii/
class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return 0;
        }
        int jumps = 1;
        int ladder = nums[0]; // largest size of current jump
        int stairs = nums[0]; // ladder steps to make jump
        
        for (int i = 1; i < size-1; i++) {
            if ((i + nums[i]) >= ladder) {
                ladder = i+nums[i];
            }
            stairs--;
            if (stairs == 0) {
                jumps++;
                stairs = ladder - i;
            }
        }
        return jumps;
    }
};