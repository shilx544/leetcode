class Solution {
public:
    void helper(const string& digits, int index, string tmp) {
        if (digits.size() == index) {
            result.push_back(tmp);
            return;
        }
        char currentNum = digits[index];
        auto& alphaList = m[currentNum];
        index++;
        for (char& c:alphaList) {
            helper(digits, index, tmp+c);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty() || digits.find("1") != string::npos) {
            return {};
        }
        helper(digits, 0, "");
        return result;
    }

private:
    map<char, vector<char>> m {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},
    };
    vector<string> result;
};