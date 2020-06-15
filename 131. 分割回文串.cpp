class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        helper(s, res, {});
        return res;
    }
    void helper(string s, vector<vector<string>>& res, vector<string> path) {
        if (s.size() == 0) {
            res.push_back(path);
            return;
        }
        for (int i = 1; i <= s.size(); i++) {
            string pre = s.substr(0, i);
            if (isPalindrome(pre)) {
                path.push_back(pre);
                helper(s.substr(i), res, path);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s) {
        int size = s.size();
        for (int i = 0, j = size-1; i <= j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};