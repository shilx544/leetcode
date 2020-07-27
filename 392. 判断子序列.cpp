class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();

        if (s.empty()) {
            return true;
        }

        if (t.empty()) {
            return false;
        }
        int pos = 0;
        for (int i = 0; i < m; ++i) {
            bool find = false;
            for (int j = pos; j < n; ++j) {
                if (s[i] == t[j]) {
                    pos = j + 1;
                    find = true;
                    break;
                }
            }

            if (!find) {
                return false;
            }
        }
        return true;
    }
};