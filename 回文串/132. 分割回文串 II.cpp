class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> st(n, vector<bool>(n));
        for(int j = 0; j < n; j++) {
            for(int i = j; i >= 0; i--) {
                if(i == j)
                    st[i][j] = true;
                else if(j - i + 1 == 2)
                    st[i][j] = (s[i] == s[j]);
                else
                    st[i][j] = (s[i] == s[j]) && st[i+1][j-1];
            }
        }
        vector<int> f(n);
        for(int j = 1; j < n; j++) {
            if(st[0][j])
                f[j] = 0;
            else {
                f[j] = f[j-1] + 1;
                for(int i = 1; i < j; i++) {
                    if(st[i][j])
                        f[j] = min(f[j], f[i-1] + 1);
                }
            }
        }
        return f[n-1];
    }
};