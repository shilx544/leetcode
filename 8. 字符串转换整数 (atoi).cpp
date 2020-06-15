class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        int flag = 1;
        int i = 0;
        // 排除掉空格
        while(str[i] == ' ') ++i;
        // 判断正负
        if (str[i] == '-') flag = -1;
        if (str[i] == '+' || str[i] == '-') ++i;
        for (; i < str.size() && isdigit(str[i]); ++i) {
            res = res * 10 + str[i]-'0';
            if (res >= INT_MAX && flag == 1) return  INT_MAX;
            if (res > INT_MAX && flag == -1) return  INT_MIN;
        }
        return res * flag;
    }
};

class Solution {
public:
    int myAtoi(string str)
{
    int num=0;
    istringstream str_1(str);
    str_1 >> num;
    if (num > INT_MAX)
        return INT_MAX;
    else if (num < INT_MIN)
        return INT_MIN;
    else
        return num;
}
};