class Solution {
private:
    void dfs(int k, int target, int begin, vector<vector<int>>& result, vector<int>& path) {
        if (target == 0 && k == 0) {
            result.push_back(path);
            return;
        }

        for (int i = begin; i <= 9; ++i) {
            path.push_back(i);
            dfs(k-1, target-i, i+1, result, path);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(k, n, 1, result, path);
        return result;
    }
};