bool cmp(vector<int>& a, vector<int>& b) {
    if (a[0] < b[0]) {
        return true;
    } else if (a[0] == b[0] && a[1] < b[1]) {
        return true;
    }
    return false;
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) {
            return 0;
        }
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp(envelopes.size(), 1);
        for (int i = 0; i < envelopes.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                if (envelopes[i][0] > envelopes[j][0] && 
                    envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};