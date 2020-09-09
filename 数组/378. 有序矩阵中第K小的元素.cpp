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
        struct point {
            int val, x, y;
            point(int val, int x, int y) : val(val), x(x), y(y) {}
            bool operator> (const point& a) const { return this->val > a.val; }
        };
        
        priority_queue<point, vector<point>, greater<point>> que;
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            que.emplace(matrix[i][0], i, 0);
        }
        for (int i = 0; i < k - 1; i++) {
            point now = que.top();
            que.pop();
            if (now.y != n - 1) {
                que.emplace(matrix[now.x][now.y + 1], now.x, now.y + 1);
            }
        }
        return que.top().val;
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