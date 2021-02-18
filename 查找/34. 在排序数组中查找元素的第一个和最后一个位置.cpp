class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int min = -1, max = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                if (min == -1) {
                    min = i;
                } else {
                    min = min < i ? min : i;
                }
                max = max > i ? max : i;
            }
        }

        result.push_back(min);
        result.push_back(max);
        
        return result;
    }
};