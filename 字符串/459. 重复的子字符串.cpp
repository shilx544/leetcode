class Solution {
public:
    bool repeatedSubString(string p, string s) {
        if (p.empty() || s.empty()) {
            return false;
        }
        int m = p.size();
        int n = s.size();
        if (n % m != 0) {
            return false;
        }

        int times = n / m;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < times; ++j) {
                if (p[i] != s[i + j * m]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = 1; i <= n / 2; ++i) {
            string sub = s.substr(0, i);
            if (repeatedSubString(sub, s)) {
                return true;
            }
        }
        return false;
    }

    bool kmp(const string& query, const string& pattern) {
        int n = query.size();
        int m = pattern.size();
        vector<int> fail(m, -1);
        for (int i = 1; i < m; ++i) {
            int j = fail[i - 1];
            while (j != -1 && pattern[j + 1] != pattern[i]) {
                j = fail[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                fail[i] = j + 1;
            }
        }
        int match = -1;
        for (int i = 1; i < n - 1; ++i) {
            while (match != -1 && pattern[match + 1] != query[i]) {
                match = fail[match];
            }
            if (pattern[match + 1] == query[i]) {
                ++match;
                if (match == m - 1) {
                    return true;
                }
            }
        }
        return false;
    }

    bool repeatedSubstringPattern(string s) {
        return kmp(s + s, s);
    }
};