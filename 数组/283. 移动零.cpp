class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int m = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                m += 1;
                continue;
            }

            if (m > 0) {
                nums[i-m] = nums[i];
            }
        }

        for (int i = n-1; i > n-1-m; --i) {
            nums[i] = 0;
        }
        return;
    }
};