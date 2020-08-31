class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int totalLeft = (m+n+1) / 2;

        int left = 0;
        int right = m;

        while (left < right) {
            int i = left + (right - left + 1) / 2;
            int j = totalLeft - i;
            if (nums1[i - 1] > nums2[j]) {
                right = i - 1;
            } else {
                left = i;
            }
        }
        int i = left;
        int j = totalLeft - i;
        int nums1Left = i == 0 ? INT_MIN : nums1[i - 1]; 
        int nums1Right = i == m ? INT_MAX : nums1[i]; 
        int nums2Left = j == 0 ? INT_MIN : nums2[j - 1];
        int nums2Right = j == n ? INT_MAX : nums2[j];

        if ((m+n)%2 == 1) {
            return max(nums1Left, nums2Left);
        } else {
            return static_cast<double>((max(nums1Left, nums2Left) + min(nums1Right,nums2Right))) / 2;
        }
    }
};