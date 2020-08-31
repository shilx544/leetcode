class Solution {
public:
    int max(int a, int b) {
        return a > b ? a :b;
    }
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int size = s.size();
        string sub = "";
        for (int i = 0; i < size; ++i) {
            if (sub.find(s[i]) == string::npos) {
                sub += s[i];
                result = max(result, sub.size());
            } else {
                int pos = sub.find(s[i]);
                sub = sub.substr(pos+1);
                sub += s[i];
            }
        }
        return result;
    }
};