class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0) {
            return result;
        }

        result.push_back({1});
        if (numRows == 1) {
            return result;
        }
        result.push_back({1, 1});
        if (numRows == 2) {
            return result;
        }
        for (int i = 2; i < numRows; ++i) {
            vector<int> v = result.back();
            vector<int> tmp;
            tmp.push_back(1);
            for (int j = 1; j < v.size(); ++j) {
                int jj = v[j] + v[j-1];
                tmp.push_back(jj);
            }
            tmp.push_back(1);
            result.push_back(tmp);
        }
        return result;
    }
};