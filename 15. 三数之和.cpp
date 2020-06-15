class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for (int first = 0; first < n-1; ++first) {
            if (nums[first] > 0) {
                break;
            }
            if (first > 0 && nums[first] == nums[first-1]) {
                // 跳过重复数据
                continue;
            }

            int third = n-1;
            int target = -nums[first];
            for (int second = first+1; second < n; ++second) {
                if (second > first+1 && nums[second] == nums[second-1]) {
                    // 跳过重复数据
                    continue;
                }
                // 确保third在second的右侧
                while(third > second && nums[second] + nums[third] > target) {
                    --third;
                }

                if (second == third) {
                    // 两数相遇，必然不相等，退出
                    break;
                }

                if (nums[second] + nums[third] == target) {
                    result.push_back({nums[first],nums[second],nums[third]});
                }
            }
        }
        return result;
    }
};