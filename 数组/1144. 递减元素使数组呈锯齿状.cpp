class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int min1 = 0;
        int min2 = 0;
        int flag = -1;
        int flag2 = 1;
        for (int i = 1; i < nums.size(); ++i) {
            // 奇位突出
            int lost = nums[i] - nums[i-1];
            if (lost * flag < 0) {
                flag *= -1;
            } else {
                min1 += abs(lost) + 1;
            }
            
            if (lost * flag2 < 0) {
                flag2 *= -1;
            } else {
                min2 += abs(lost) + 1;
            }
        }

        return min(min1, min2);
    }
};