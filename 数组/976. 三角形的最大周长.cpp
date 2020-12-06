class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        if (A.size() < 3) {
            return 0;
        }
        sort(A.begin(), A.end());
        int size = A.size()-1;
        int a1 = size;
        int a2 = size-1;
        int a3 = size-2;
        int result = 0;
        while(a3 >= 0) {//终止条件即为最小值到达数组前端了
            if(A[a1] < A[a3] + A[a2]) {
                result = A[a1] + A[a2] + A[a3];                
                return result;//直接返回即可，满足贪心策略
            }
            a1--;
            a2--;
            a3--;
        }
        return result;
    }
};