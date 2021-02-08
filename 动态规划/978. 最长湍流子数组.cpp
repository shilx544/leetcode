class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> dp2(n, 1);
        int symbol = 1;
        int symbol2 = -1;
        for (int i = 1; i < n; ++i) {
            if (arr[i] - symbol * arr[i-1] < 0) {
                dp[i] = dp[i-1] + 1;
            }
            symbol *= -1;
            cout << "pos:" << dp[i] << endl;
        }

        for (int i = 1; i < n; ++i) {
            if (arr[i] - symbol2 * arr[i-1] < 0) {
                dp2[i] = dp2[i-1] + 1;
            }
            symbol2 *= -1;
                cout << "neg:" << dp2[i] << endl;
        }
        int result1 = *max_element(dp.begin(),dp.end());
        int result2 = *max_element(dp2.begin(),dp2.end());
        return max(result1, result2);
    }
};