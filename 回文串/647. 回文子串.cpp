class Solution {
public:
    bool isSubsequence(const string& s) {
        if (s.empty()) return false;
        if (s.size() == 1) return true;
        int i = 0, j = s.size()-1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }

    int countSubstrings(string s) {
        if (s.empty()) return 0;
        if (s.size() == 1) return 1;
        int n = s.size();
        int result = 1;

        for (int i = 1; i < n; ++i) {
            result++;
            for (int j = 0; j < i; ++j) {
                string tmp = s.substr(j, i-j+1);
                if (isSubsequence(tmp)) {
                    result++;
                }
            }
        }
        return result;
    }

    int countSubstrings(string s) {
        int n = s.size();
        string t = "$#";
        for (const char &c: s) {
            t += c;
            t += '#';
        }
        n = t.size();
        t += '!';

        auto f = vector <int> (n);
        int iMax = 0, rMax = 0, ans = 0;
        for (int i = 1; i < n; ++i) {
            // 初始化 f[i]
            f[i] = (i <= rMax) ? min(rMax - i + 1, f[2 * iMax - i]) : 1;
            // 中心拓展
            while (t[i + f[i]] == t[i - f[i]]) ++f[i];
            // 动态维护 iMax 和 rMax
            if (i + f[i] - 1 > rMax) {
                iMax = i;
                rMax = i + f[i] - 1;
            }
            // 统计答案, 当前贡献为 (f[i] - 1) / 2 上取整
            ans += (f[i] / 2);
        }

        return ans;
    }
};