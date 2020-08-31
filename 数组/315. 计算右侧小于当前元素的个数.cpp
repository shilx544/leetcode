class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        for (int i = 0; i < n; ++i) {
            int smaller = 0;
            for (j = i+1; j < n; ++j) {
                if (nums[j] < nums[i]) {
                    smaller++;
                }
            }
            dp[i] = smaller
            
        }
        return dp;
    }
};