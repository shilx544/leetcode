class Solution {
public:
    int reverse(int x) {
        long result = 0;
        if (x == INT_MIN)
        {
            return 0;
        }
        if (x < 0)
        {
            return -reverse(-x);
        }

        while (x > 0) {
            int digit = x % 10;
            result = result * 10 + digit;
            x /= 10;
        }

        if (result >= INT_MAX) return 0;
        return (int) result;
    }

    int reverse(int x) {
       if (x == INT_MIN)
        {
            return 0;
        }
        if (x < 0)
        {
            return -reverse(-x);
        }
        string s = to_string(x);
        long result = atoi(s.reverse(s.begin(),s.end()));

        if (result >= INT_MAX) return 0;
        return (int) result
    }
};