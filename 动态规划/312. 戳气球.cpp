class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size() + 2;
        // 定义状态转移方程为[min,max]区间内获取的最高金币数
        vector<vector<int> > dp(n, vector<int>(n, 0));

        nums.insert(nums.begin(),1);
        nums.push_back(1);

        for (int i = n-1; i >=0; --i) {
            for (int j = i; j < n; ++j) {
                if (j - i < 2) {
                    continue;
                }
                for (int pos = i+1; pos < j; ++pos) {
                    dp[i][j] = max(dp[i][j], dp[i][pos] + dp[pos][j] + nums[i]*nums[pos]*nums[j]);
                }
            }
        }
        return dp[0][n-1];
    }
};