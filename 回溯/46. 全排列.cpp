class Solution {
public:
    void helper(vector<int>& nums, vector<int>& candidates, vector<vector<int>>& result, int size) {
        if (candidates.size() == size) {
            result.push_back(candidates);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            candidates.push_back(nums[i]);
            vector<int> tmp;
            for (int j = 0; j < nums.size(); ++j) {
                if (j != i) {
                    tmp.push_back(nums[j]);
                }
            }
            helper(tmp, candidates, result, size);
            candidates.pop_back();
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> candidates;
        helper(nums, candidates, result, nums.size());
        return result;
    }
};