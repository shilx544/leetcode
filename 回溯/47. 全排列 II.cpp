class Solution {
private:
    void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& path) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = begin; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            dfs(nums, result, path, begin+1);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;

        if (nums.empty()) {
            return result;
        }

        sort(nums.begin(), nums.end());
        vector<int> path;
        dfs(nums, result, path, 0);
        return result;
    }
};