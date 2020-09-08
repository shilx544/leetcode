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