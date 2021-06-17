class Solution {
public:
    static const regex pattern;

    bool isNumber(string str) {
        return regex_match(str, pattern);
    }
};

const regex Solution::pattern("[+-]?(?:\\d+\\.?\\d*|\\.\\d+)(?:[Ee][+-]?\\d+)?");