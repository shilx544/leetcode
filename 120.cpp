class Solution {
public:

    // int getMin(vector<int>& nums, int pos, int result) {

    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        vector<vector<int>> dp(triangle);
        dp[0][0] = triangle[0][0];
        dp[1][0] = triangle[0][0] + dp[1][0];
        dp[1][1] = triangle[0][0] + dp[1][1];
        for (int i = 2; i < size; ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) {
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                } else if (j == triangle[i].size()-1) {
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                } else {
                    dp[i][j] = min(dp[i-1][j-1]+triangle[i][j], dp[i-1][j]+triangle[i][j]);
                }

            }
        }
        return *std::min_element(dp[size-1].begin(), dp[size-1].end() ) ;
    }
};