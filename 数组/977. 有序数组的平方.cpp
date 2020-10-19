bool cmp(const int& a, const int& b) {
    return abs(a) < abs(b) ? true : false;
}

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        sort(A.begin(), A.end(), cmp);
        vector<int> result;
        for (int &a : A) {
            result.push_back(a*a);
        }
        return result;
    }
};