class Solution {
public:
void nextPermutation(vector<int>& nums) {
    int pos = nums.size()-1;
    while (pos > 0 && nums[pos] <= nums[pos-1]) {
        pos--;
    }
    reverse(nums.begin()+pos, nums.end()); // 逆序
    if (pos > 0) {
        for (int start = pos; start < nums.size(); ++start) {
            if (nums[start] > nums[pos-1]) {
                swap(nums[start], nums[pos-1]);
                break;
            }
        }
    }
    return;
}
};