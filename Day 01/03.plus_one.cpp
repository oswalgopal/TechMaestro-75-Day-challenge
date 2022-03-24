// https://leetcode.com/problems/plus-one/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int i = size-1;
        int carry = 0;
        vector<int> result;
        while(i >= 0) {
            int sum = digits[i] + carry;
            if (i == size-1) {
                sum += 1;
            }
            carry = 0;
            if (sum > 9) {
                carry = sum / 10;
                sum = sum % 10;
            }
            result.push_back(sum);
            i--;
        }
        if (carry) {
            result.push_back(carry);
            carry = 0;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};