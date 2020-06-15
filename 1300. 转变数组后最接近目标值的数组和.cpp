class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        if (n == 0) return 0;

        sort(arr.begin(), arr.end());
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            double avg = (double)(target - sum) / (n-i);
            int iAvg = static_cast<int>(avg);

            if (arr[i] >= avg) {
                if (avg-iAvg > 0.5) {
                    return iAvg+1;
                } else {
                    return iAvg;
                }
            }
            sum += arr[i];
        }
        return *max_element(arr.begin(), arr.end());
    }
};