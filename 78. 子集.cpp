class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> ret;
        vector<int> tmpres;
        int len = S.size();
        if(len == 0) return ret;
        sort(S.begin(), S.end());
        subsets_helper(S, tmpres, 0, ret);
        return ret;
    }

    void subsets_helper(vector<int>& S, vector<int>& tmpres, int ileaf, vector<vector<int>>& ret)
    {
        //达到叶子结点，一个集合元素选择结束
        if(ileaf == S.size())
        {
            ret.push_back(tmpres);
            return;
        }

        //选择ileaf元素
        tmpres.push_back(S[ileaf]);
        subsets_helper(S, tmpres, ileaf + 1, ret);

        //不选择ileaf元素，将ileaf pop出来
        tmpres.pop_back();
        subsets_helper(S, tmpres, ileaf + 1, ret);
    }
};