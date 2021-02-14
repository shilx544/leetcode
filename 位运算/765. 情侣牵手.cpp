class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int result = 0;
        for (int i = 0; i < n-1; i+=2) {
            if (row[i] == (row[i+1] ^ 1)) {
                continue;
            }
            for (int j = i+1; j < n; ++j) {
               if (row[i] == (row[j] ^ 1)) {
                   swap(row[i+1], row[j]);
               }
            }
            result++;
        }
        return result;
    }
};

class Solution(object):
    def minSwapsCouples(self, row):
        """
        :type row: List[int]
        :rtype: int
        """
        N = len(row)
        res = 0
        for i in range(0, N - 1, 2):
            if row[i] == row[i + 1] ^ 1:
                continue
            for j in range(i + 1, N):
                if row[i] == row[j] ^ 1:
                    row[i + 1], row[j] = row[j], row[i + 1]
            res += 1
        return res