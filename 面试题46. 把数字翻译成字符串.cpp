class Solution {
public:
    int translateNum(int num) {
        string sNums = '0' + to_string(num);
        int n = sNums.size();
        vector<int> dp(n, 0);

        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < n; ++i) {
            if((sNums[i] <= '6' && sNums[i-1] == '2') || (sNums[i-1] == '1')) {
                dp[i] = dp[i-2]+dp[i-1];
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp.back();
    }
};