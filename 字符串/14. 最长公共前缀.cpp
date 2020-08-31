bool cmp(const string& str1, const string& str2) {
    return str1.size() < str2.size() ? true : false;
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        if (strs.empty()) {
            return result;
        }

        sort(strs.begin(), strs.end(),cmp);
        string tmp = strs[0];
        for (int i = 0; i < tmp.size(); ++i) {
            bool isSame = true;
            for (int j = 0; j < strs.size(); ++j) {
                if (strs[j][i] != tmp[i]) {
                    isSame = false;
                    return result;
                }
            }

            if (isSame) {
                result += tmp[i];
            }
        }
        return result;
    }
};