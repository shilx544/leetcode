// 单调栈
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, -1);
        stack<int> stk;
        for (int i = 0; i < n * 2 - 1; i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
                ret[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }
        return ret;
    }
};

// 循环搜索
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result;
        vector<int> nums2 = nums;
        for (auto& num : nums) {
            nums2.emplace_back(num);
        }
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums2.size(); ++j) {
                if (nums2[j] > nums[i]) {
                    result.emplace_back(nums2[j]);
                    break;
                }
                if (j == nums2.size()-1) {
                    result.emplace_back(-1);
                }
            }
        }
        return result;
    }
};