class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        string nums = to_string(x);
        int n = nums.size();
        for (int i = 0, j = n-1; j-i >= 1; ++i, --j) {
            if (nums[i] != nums[j]) {
                return false;
            }
        }
        return true;
    }
};