class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        if (haystack.find(needle)!= string::npos) {
            return haystack.find(needle);
        } else {
            return -1;
        }
    }
};