class Solution {
public:
    int longestMountain(vector<int>& A) {
        int i = 1;
        int result = 0;

        while (i < A.size()) {
            int inc = 0, dec = 0;
            while (i < A.size() && A[i] > A[i - 1]) {
                i++;
                inc++;
            }

            while (i < A.size() && A[i] < A[i - 1]) {
                i++;
                dec++;
            }

            if (inc > 0 && dec > 0) {
                result = max(result, inc+dec+1);
            }
            while (i < A.size() && A[i] == A[i-1]) {
                i++;
            }

        }
        return result;
    }
};