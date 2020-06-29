class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int result = 0;
        if (A.size() < 2) {return result;}

        for (int i = 1; i < A.size(); i++) {
            for(int j = 0; j < i; ++j) {
                int tmp = A[i] + A[j] + j - i;
                result = tmp > result ? tmp : result;
            }
        }
        return result;
    }

    int maxScoreSightseeingPair(vector<int>& A) {
        int ans = 0, mx = A[0] + 0;
        for (int j = 1; j < A.size(); ++j) {
            ans = max(ans, mx + A[j] - j);
            // 边遍历边维护
            mx = max(mx, A[j] + j);
        }
        return ans;
    }
}