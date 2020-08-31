class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        for (int &num:nums) {
            if (num > 0) {
                s.insert(num);
            }
        }

        int result = 1;
        auto p = s.begin();
        for (; p != s.end(); ++p) {
            if (*p == result) {
                result++;
            } else if (*p > result) {
                return result;
            }
        }
        return result;
    }

    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 1;
        }

        for (int i = 0; i < n; ++i) {
            while(nums[i] > 0 && nums[i] < n && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            }
        }

        for (int i = 1; i < n; ++i) {
            if (nums[i] != i) {
                return i;
            }
        }

        return nums[0]==n?n+1:n;
    }
};