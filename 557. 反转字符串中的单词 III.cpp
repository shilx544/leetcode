class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int start = 0, end = 0;
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                end = i-1;
                string sub = s.substr(start, end-start+1);
                reverse(sub.begin(),sub.end());
                result += sub + " ";
                start = i + 1;
            } else if (i == n-1) {
                end = i;
                string sub = s.substr(start, end-start+1);
                reverse(sub.begin(),sub.end());
                result += sub;
            }
        }
        return result;
    }
};