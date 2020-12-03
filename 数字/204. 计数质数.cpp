class Solution {
public:
    int countPrimes(int n) {
        int result = 0;
        vector<int> isPrime(n, 1);

        for(int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                result++;
                if ((int64_t) i*i < n) {
                    for (int j = i * i; j < n; j+=i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return result;
    }
};