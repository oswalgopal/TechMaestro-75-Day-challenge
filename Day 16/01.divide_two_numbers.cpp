// https://leetcode.com/problems/divide-two-integers/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // INT_MIN/(-1) = INT_MAX
        }
        long long int a = abs(dividend);
        long long int b = abs(divisor);
        long long int result = 0;
        
        while(a-b >= 0) { // can we take divisor from dividend
            int x = 0; // 2^0 = 1
            while(a-((b << 1) << x) >= 0) {
                // 10-3 << 1 << 0 => 10 - 6 = 4 // can take 3 two times
                // 10-3 << 1 << 1 => 10 - 12 = -1 // so can't
                x++;
            }
            result += (1 << x); // 1 << 1 => 2 
            a -= (b << x); // 10 - (3<<1) => 4
        }
        
        return (dividend >= 0) == (divisor >= 0) ? result :-result;
    }
};