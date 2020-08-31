class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto j:nums) {
            m[j] = j;
        }

        int result = 0;
        for (int i=0; i < nums.size(); ++i) {
            if (!m.count(nums[i]-1)) {
                int cur = nums[i];
                while(m.count(cur+1)) {
                    ++cur;
                }
                result=max(result, cur-nums[i] + 1);
            }
        }
        return result;
    }
};