class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> dp2(n, 1);
        for (int i = 1; i < n; ++i) {
            if (arr[i] - arr[i-1] < 0) {
                dp[i] = dp2[i-1] + 1;
            }
            if (arr[i] - arr[i-1] > 0) {
                dp2[i] = dp[i-1] + 1;
            }
        }

        int result1 = *max_element(dp.begin(),dp.end());
        int result2 = *max_element(dp2.begin(),dp2.end());
        return max(result1, result2);
    }
};