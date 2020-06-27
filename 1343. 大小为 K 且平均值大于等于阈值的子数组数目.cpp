class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        // 滑动窗口法，先固定4个元素的值，再逐一进行替换，直到遍历完成
        int n = arr.size();
        int sum = 0;
        int count = 0;
        for (int i = 0; i < k; ++i) {
            sum += arr[i];
        }

        if (sum >= threshold*k) {
            count++;
        }

        for (int i = 0; i < n-k; ++i) {
            sum -= arr[i];
            sum += arr[i+k];
            if (sum >= threshold*k) count++;
        }
        return count;
    }
};