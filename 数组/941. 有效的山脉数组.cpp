class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) {
            return false;
        }
        
        int top = 0;
        for (size_t i = 1; i < A.size()-1; ++i) {
            if (A[i] > A[i-1] && A[i] > A[i+1]) {
                top = i;
                break;
            }

            if (A[i] <= A[i-1]) {
                return false;
            }
        }

        if (top  == 0) {
            return false;
        }

        for (size_t j = A.size()-2; j > top; --j) {
            if (A[j] <= A[j+1]) {
                return false;
            }
        }

        
        return true;
    }
};