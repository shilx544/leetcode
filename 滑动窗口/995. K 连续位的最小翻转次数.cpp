class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int N = A.size();
        queue<int> que;
        int result = 0;
        for (int i = 0; i < N; ++i) {
            if (!que.empty() && i >= que.front() + K) {
                que.pop();
            }
            if (que.size() % 2 == A[i]) {
                if (i + K > N) {
                    return -1;
                }
                que.push(i);
                result ++;
            }
        }
        return result;
    }
};