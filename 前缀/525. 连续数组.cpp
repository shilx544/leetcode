class Solution {
public:
    int findMaxLength(vector<int>& nums) {
	    int n = nums.size();
        vector<int> sum = vector<int>(n+1, 0);

        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i-1] + (nums[i-1] == 1 ? 1 : -1);
        }
        int ans = 0;
        map<int, int> hmap;
        for (int i = 2; i <= n; ++i) {
            if (hmap.find(sum[i-2]) == hmap.end()) {
                hmap[sum[i-2]] = i-2;
            }
            if (hmap.find(sum[i]) != hmap.end()) {
                ans = max(ans, i - hmap[sum[i]]);
            }
        }
        return ans;
    }
};