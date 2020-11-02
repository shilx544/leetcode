class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if (nums.empty() || nums1.empty() || nums2.empty()) {
            return result;
        }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int pos = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            if (i > 0 && nums1[i] == nums1[i - 1]) {
                continue;
            }
            for (int j = pos; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) {
                    result.push_back(nums1[i]);
                    pos = j+1;
                }
            }
        }
        return result;
    }
};