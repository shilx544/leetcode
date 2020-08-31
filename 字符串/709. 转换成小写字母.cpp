class Solution {
public:
    string toLowerCase(string str) {
        for (auto &c : str) {
            if (c >= 'A' && c <= 'Z') {
                c = c + 32;
            }
        }
        return str;
    }
};