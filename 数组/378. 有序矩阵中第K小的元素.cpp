class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> v;
        for (vector<int> line:matrix) {
            for(int num:line) {
                v.push_back(num);
            }
        }

        sort(v.begin(), v.end());
        return v[k-1];
    }

    // 归并排序
    int kthSmallest(vector<vector<int>>& matrix, int k) {

    }

    // 二分查找
    bool check(vector<vector<int>>& matrix, int mid, int k, int n) {
        int i = n - 1;
        int j = 0;
        int num = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {
                num += i + 1;
                j++;
            } else {
                i--;
            }
        }
        return num >= k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        while (left < right) {
            // cout << left << "|" << right << "|" << ((right - left) >> 1) << endl;
            int mid = left + ((right - left) >> 1);
            if (check(matrix, mid, k, n)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

};