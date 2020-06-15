class Solution {
public:
    void reverseString(vector<char>& s) {
        helper(s,0,s.size());
    }

    void helper(vector<char>&s, int pos, int len) {
        if (pos >= len/2) {
            return;
        }
        char tmp = s[pos];
        s[pos] = s[len-pos-1];
        s[len-pos-1] = tmp;

        helper(s, pos+1, len);
    }
};