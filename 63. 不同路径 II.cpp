class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> dp(n,0);
        dp[0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                    continue;
                }
                if (j-1 >= 0) {
                    dp[j] += dp[j-1];
                }
            }
        }
        return dp[n-1];
    }
};