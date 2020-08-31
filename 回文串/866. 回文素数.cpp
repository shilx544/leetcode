bool isPrime(int n) {
    if (n <= 3) {
        return n > 1;
    }
    int squareRoot=1;
    while(squareRoot*squareRoot<n){
        squareRoot++;
    }
    for (int i = 2; i  <= squareRoot; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool isPalindrome(int n) {
    int i = n;
    int m = 0;
    while (i > 0) {
        m = m*10+i%10;
        i /= 10;
    }
    return m == n;
}

class Solution {
public:
    int primePalindrome(int N) {
        while (1) {
            if ((N%2 == 0 && N > 2) || (N%5 == 0 && N > 5) || (N > 10000000 && N < 99999999)) {
                N++;
                continue;
            }
            if (isPalindrome(N)) {
                if (isPrime(N)) {
                    return N;
                }
            }
            N++;
        }
    }
};