class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for(int i=0;i<word.size();i++) {
            if(word[i] >= 'A' && word[i] <= 'Z') {
                cnt++;
            }
        }
        if(cnt == word.size() || cnt == 0 || (cnt == 1 && word[0] >= 'A' && word[0] <= 'Z')) {
            return true;
        }
        return false;
    }
};