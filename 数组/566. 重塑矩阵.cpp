class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        int n = nums[0].size();
        if (m * n != r * c) {
            return nums;
        }

        vector<vector<int>> result;
        queue<int> que;
        for (auto num : nums) {
            for (auto i : num) {
                que.push(i);
            }
        }

        for (int i = 0; i < r; ++i) {
            vector<int> tmp;
            for (int j = 0; j < c; ++j) {
                int m = que.front();
                tmp.push_back(m);
                que.pop();
            }
            result.push_back(tmp);
        }
        return result;
    }
};