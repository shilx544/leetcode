class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ppre = 0, pre = nums[0];
        unordered_set<int> se;
        for (int i=2;i<=n;++i) {
            se.insert(ppre%k);
            pre += nums[i-1];
            if (se.count(pre%k) > 0) return true;
            ppre += nums[i-2];
        }
        return false;
    }
};