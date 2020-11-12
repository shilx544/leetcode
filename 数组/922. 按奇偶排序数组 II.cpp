class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> m;
        vector<int> n;
        for (auto &i : A) {
            if (i % 2 == 0) {
                m.push_back(i);
            } else {
                n.push_back(i);
            }
        }
        vector<int> result;

        for (int i = 0; i < n.size(); ++i) {
            result.push_back(m[i]);
            result.push_back(n[i]);
        }
        return result;
    }
};