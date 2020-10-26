class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> result;
        unordered_map<char, int> m;
        int start = 0;
        int end = 0;
        if (S.empty()) {
            return result;
        }

        for (size_t i = 0; i < S.size(); ++i) {
            m[S[i]] = i;
        }

        for (size_t i = 0; i < S.size(); ++i) {
            end = max(end, m[S[i]]);
            if (i == end) {
                result.push_back(end-start+1);
                start = end+1;
            }
        }
        return result;
    }
};