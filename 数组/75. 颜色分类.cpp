class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[zero]);
                if (zero < one) {
                    swap(nums[i], nums[one]);
                }
                zero++;
                one++;
            } else if (nums[i] == 1) {
                swap(nums[i], nums[one]);
                one++;
            }
        }

    }

    void sortColors2(vector<int>& nums) {
        int zero = 0;
        int two = nums.size()-1;

        for (int i = 0; i < nums.size(); ++i) {
            while (i <= two && nums[i] == 2) {
                swap(nums[i], nums[two]);
                two--;
            }

            if (nums[i] == 0) {
                swap(nums[i], nums[zero]);
                zero++;
            }
        }
    }
};