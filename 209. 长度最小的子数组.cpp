class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int result = INT_MAX;
        for(int i = 0; i < nums.size(); ++i) {
            int count = 0;
            int sum = 0;

            int j = i;
            while (sum < s && j < nums.size()) {
                sum += nums[j];
                ++j;
                ++count;
            }

            if (count < result && sum >= s) {
                result = count;
            }
        }
        if (result == INT_MAX) {
            return 0;
        }
        return result;
    }

    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        int start = 0, end = 0;
        int sum = 0;
        while (end < n) {
            sum += nums[end];
            while (sum >= s) {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};