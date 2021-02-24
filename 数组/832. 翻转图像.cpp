class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();

        for (auto& a : A) {
            reverse(a.begin(), a.end());
            for (auto& aa : a) {
                if (aa == 0) {
                    aa = 1;
                } else if (aa == 1) {
                    aa = 0;
                }
            }
        }

        return A;
    }
};