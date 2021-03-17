class Solution {
public:
    int distanceDFS(string s, string t, int sbg, int tbg, map<pair<int, int>, int>& mp)
    {
        // 退出条件
        if (tbg == t.size()) {
            return 1;
        }
        if (sbg > s.size()) {
            return 0;
        }
        if (mp.count({ sbg, tbg }) != 0) {
            return  mp[{sbg, tbg}];
        }
        int val = 0;
        for (int i = sbg; i < s.size(); i++) {
            if (t[tbg] != s[i]) {
                continue;
            }
            val += distanceDFS(s, t, i + 1, tbg + 1, mp);
        }
        return mp[{sbg, tbg}] = val;
    }

    int numDistinct(string s, string t) {
        int ans = 0;
        map<pair<int, int>, int> mp;
        return distanceDFS(s, t, 0, 0, mp);
    }
};