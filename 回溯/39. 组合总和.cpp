class Solution {
private:
    void helper(int target, int begin, vector<int>& nums, vector<int>& candidates, vector<vector<int>>& result) {
        if (0 == target) {
            result.push_back(nums);
            return;
        } else if (0 > target) {
            return;
        }

        for (int i = begin; i < candidates.size(); ++i) {
            if (target - candidates[i] < 0) {
                continue;
            }
            nums.push_back(candidates[i]);
            helper(target-candidates[i], i, nums, candidates, result);
            nums.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if (candidates.empty()) {
            return result;
        }
        sort(candidates.begin(), candidates.end());
        vector<int> nums;
        helper(target, 0, nums, candidates, result);
        return result;
    }
};