class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0; maxAns = nums[0];
        for (auto& x: nums) {
            pre = max(x, pre+x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};