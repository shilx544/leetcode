class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 1; i < n; ++i) {
            int gap = nums[i] - nums[i-1];
            if(gap > 1) {
                for(int j = nums[i-1]+1; j < nums[i]; ++j) {
                    result.push_back(j);
                }
            }
        }
        if (n > 0) {
            for(int i = 1; i < nums[0]; ++i) {
                result.push_back(i);
            }
            for (int i = nums[n-1]+1; i <= n; ++i) {
                result.push_back(i);
            }
        }
        return result;
    }
};