class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        if (nums.size() < 4) {
            return result;
        }

        unordered_map<int, int> cnt;
        for (int c = n - 2; c >= 2; --c) {
            cnt[nums[c + 1]] += 1;
            for (int a = 0; a < c; ++a) {
                for (int b = a + 1; b < c; ++b) {
                    if (int sum = nums[a] + nums[b] + nums[c]; cnt.count(sum)) {
                        result += cnt[sum];
                    }
                }
            }

        }
    }
};