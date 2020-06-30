class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int n = nums.size();
        vector<int> dp(n,1);

        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = nums[i] > nums[i-1] ? dp[i-1] + 1 : 1;
        }

        return *max_element(dp.begin(),dp.end());
    }
};