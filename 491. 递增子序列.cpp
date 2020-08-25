class Solution {
private:
void backtracking(vector<int>& nums, vector<vector<int>>& result, vector<int>& subseq, int startIndex) {
    if (subseq.size() > 1) {
        result.push_back(subseq);
        // 注意这里不要加return，因为要取所有的可能
    }
    unordered_set<int> uset; // 使用set来对尾部元素进行去重
    for (int i = startIndex; i < nums.size(); i++) {
        if ((subseq.empty() || nums[i] >= subseq.back())
                && uset.find(nums[i]) == uset.end()) {
            subseq.push_back(nums[i]);
            backtracking(nums, result, subseq, i + 1);
            subseq.pop_back();
            uset.insert(nums[i]);//在回溯的时候，记录这个元素用过了，后面不能再用了
        }
    }
}
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subseq;
        backtracking(nums, result, subseq, 0);
        return result;
    }
};