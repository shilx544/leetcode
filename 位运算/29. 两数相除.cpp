class Solution {
public:
    int divide(int dividend, int divisor) {
    long ans = 0, up = std::fabs(dividend), down = std::fabs(divisor);
    while(up >= down) {
        long count = 1, base = down;
        while(up > (base << 1)){
            count <<= 1;
            base <<= 1;
        }
        ans += count;
        up -= base;
    }
    ans = ((dividend < 0)^(divisor < 0)) ? -ans : ans;
    return (ans > INT_MAX || ans < INT_MIN) ? INT_MAX : ans;
}
};