class Solution {
public:
    int longestValidParentheses(string s) {
        // 思路：动态规划法，有效子串必然是以右括号')'结尾
        // 如果碰到右括号，先去判断前一个是否为左括号，是的话则在dp[n-2]的基础上+2
        // 如果不是，则去看s[i-dp[i-1]-1]这个元素是否为左括号，是的话则+2，并且看与前面的是否连接成一个更长的有效括号
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n, 0);
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = i >= 2 ? dp[i-2] + 2 : 2;
                } else if (i - dp[i-1] > 0 && s[i - dp[i-1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

    int longestValidParentheses(string s) {
        int n = s.size();
        if (n == 0) return 0;
        int len = 0, max_length = 0;
        stack<int> stk;
        stk.push(-1);

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    max_length = max(max_length, i - stk.top());
                }
            }
        }
        return max_length;
    }
};