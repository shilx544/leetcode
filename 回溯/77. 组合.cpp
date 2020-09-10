/*给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
示例:
输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
class Solution {
private:
    void dfs(int n, int k, int begin, vector<int>& nums, vector<vector<int>>& result) {
        if (nums.size() == k) {
            result.push_back(nums);
            return;
        }

        for (int i = begin; i <= n; ++i) {
            nums.push_back(i);
            dfs(n, k, i+1, nums, result);
            nums.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;

        if (k <= 0 || n < k) {
			return result;
		}
		vector<int> path;
		dfs(n, k, 1, path, result);
		return result;
    }
};