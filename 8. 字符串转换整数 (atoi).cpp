class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        int flag = 1;
        int i = 0;
        while(str[i] == ' ') ++i;
        if (str[i] == '-') flag = -1;
        if (str[i] == '+' || str[i] == '-') ++i;
        for (; i < str.size() && isdigit(str[i]); ++i) {
            res = res * 10 + str[i];
            if (res >= INT_MAX && flag == 1) return  INT_MAX;
            if (res > INT_MAX && flag == -1) return  INT_MIN;
        }
        return res * flag;
    }
};