class Solution {
public:
    string countAndSay(int n) {
        string result = "1";

        for (int i = 1; i < n; ++i) {
            vector<pair<int, int>> v;
            if (result.size() == 1) {
                v.push_back(make_pair(1, result[0]-'0'));
            }
            int start = 0;
            int end = 0;
            for (int j = 1; j < result.size(); ++j) {
                if(result[j] != result[j-1]) {
                    v.push_back(make_pair(end-start+1, result[j-1]-'0'));
                    start = j;
                    end = j;
                } else {
                    end++;
                }
                if (j == result.size()-1) {
                    v.push_back(make_pair(end-start+1, result[j]-'0'));
                }
            }
            string tmp = "";
            for (auto vv : v) {
                tmp += (to_string(vv.first) + to_string(vv.second));
            }
            result = tmp;
        }
        return result;
    }
};