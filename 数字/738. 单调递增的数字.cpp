class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        int result = N;
        if (N < 10) {
            return result;
        }
        string str = to_string(N);
        for (int i = str.size()-2; i >= 0; --i) {
            if (str[i] <= str[i+1]) {
                continue;
            } else {
                str[i] -= 1;
                for (int j = i+1; j < str.size(); ++j) {
                    str[j] = '9';
                }
            }

        }
        return stoi(str);
    }
};