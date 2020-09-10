class Solution {
private:
    void dfs(int target, int begin, vector<int>& candidates, vector<int>& path, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = begin; i < candidates.size(); ++i) {
            if (candidates[i] > target) break;
            if (i > begin && candidates[i] == candidates[i-1]) continue;
            path.push_back(candidates[i]);
            dfs(target-candidates[i], i+1, candidates, path, result);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if (candidates.empty()) {
            return result;
        }
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        dfs(target, 0, candidates, path, result);
        return result;
    }
};