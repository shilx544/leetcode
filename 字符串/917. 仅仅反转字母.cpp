class Solution {
public:

    bool isLetter (char c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            return true;
        }
        return false;
    }

    string reverseOnlyLetters(string S) {
        int low = 0; int high = S.size()-1;
        while (low < high) {
            if (isLetter(S[low]) && isLetter(S[high])) {
                char tmp = S[low];
                S[low] = S[high];
                S[high] = tmp;
                low++;
                high--;
            } else if (!isLetter(S[low])) {
                low++;
            } else if (!isLetter(S[high])) {
                high--;
            }
        }
        return S;
    }
};