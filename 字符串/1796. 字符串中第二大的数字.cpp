class Solution {
public:
    int secondHighest(string s) {
        int max = -1;
        int second = -1;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                if (c - '0' > max) {
                    cout << c - '0'<< endl;
                    second = max;
                    max = c - '0';
                } else if (c - '0' < max && c - '0' > second) {
                    second = c - '0';
                }
                
            }
        }
        return second;
    }
};