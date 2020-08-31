class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        for (int i = n-1; i >= 0; --i) {
            if (i == n-k) {
                return nums[i];
            }
        }
        return 0;
    }
};