class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(1, n);
        vector<int> dp2(1, n);
        int symbol = 1;
        int symbol = -1;
        for (int i = 1; i < n; ++i) {
            if (arr[i] - symbol * arr[i-1] < 0) {
                vector[i] = vector[i-1] + 1;
                symbol *= -1;
            }
        }

        
    }
};