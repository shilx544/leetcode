class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int right = 0;
        for (int i = 1; i < nums.size(); ++i) {
            right += nums[i];
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0) {
                left += nums[i-1];
                right -= nums[i];
            }
            // cout << left << "," << right << endl;
            if (left == right) {
                return i;
            }

        }
        return -1;
    }
};