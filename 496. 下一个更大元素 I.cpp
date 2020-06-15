class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int sizeA = nums1.size();
        int sizeB = nums2.size();
        vector<int> result;
        for (int i = 0; i < sizeA; ++i) {
            bool find = false;
            for (int j = 0; j < sizeB; ++j) {
                if (nums2[j] == nums1[i]) {
                    for (int k = j + 1; k < sizeB; ++k) {
                        if (nums2[k] > nums1[i]) {
                            find = true;
                            result.push_back(nums2[k]);
                            break;
                        }
                    }
                }
            }
            if (!find) {
                result.push_back(-1);
            }
        }
        return result;
    }
};