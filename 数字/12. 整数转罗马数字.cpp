class Solution {
public:
    string intToRoman(int num) {
        vector<int> nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> romans= {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result;
        int i = 0;
        for (auto i = 0; i < nums.size(); ++i) {
            while (num >= nums[i]) {
                result += romans[i];
                num -= nums[i];
            }
        }
        return result;
    }
};