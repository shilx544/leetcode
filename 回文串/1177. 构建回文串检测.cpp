class Solution {
public:
    bool isPalindrome(const string& s, int k) {
        int low = 0, high = s.size()-1;
        int change = 0;
        while (low < high) {
            if (s[low] != s[high]) {
                change++;
            }

            if (change > k) {
                return false;
            }
            low++;
            high--;
        }
    }
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {

    }
};