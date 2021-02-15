class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                if (i == 0) {
                    dp[i] = 1;
                } else {
                    dp[i] = dp[i-1] + 1;
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                maxCount = max(maxCount, count);
                count = 0;
            }
        }
        maxCount = max(maxCount, count);
        return maxCount;
    }
};