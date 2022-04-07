// https://leetcode.com/problems/powx-n/
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        if (n == -1) {
            return 1 / x;
        }
        return (myPow(x*x, n/2)) * (myPow(x, n%2));
    }
};