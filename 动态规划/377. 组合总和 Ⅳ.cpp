/*给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。

示例:
nums = [1, 2, 3]
target = 4
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
请注意，顺序不同的序列被视作不同的组合。
因此输出为 7。
*/

class Solution {
private:
    // 回溯会超时
    int result = 0;
    void dfs(vector<int>& nums, int target, int path) {
        if (target == 0) {
            result++;
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > target) continue;
            path += nums[i];
            dfs(nums, target-nums[i], path);
            path -= nums[i];
        }
        return;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.empty()) {
            return result;
        }
        int path;
        dfs(nums, target, path);
        return result;
    }

    int combinationSum4(vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0;
        }

        int n = nums.size();
        vector<int> dp(target+1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                dp[i] += ( (i - nums[j] >= 0) ? dp[i-nums[j]] : 0);
            }
        }
        return dp[target];
    }
};