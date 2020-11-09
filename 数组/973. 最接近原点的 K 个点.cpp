bool cmp(vector<int>& a, vector<int>& b) {
    return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1] ? true : false;
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        sort(points.begin(), points.end(), cmp);
        for (int i = 0; i < K; ++i) {
            result.push_back(points[i]);
        }
        return result;
    }
};

// quick sort
class Solution {
private:
    mt19937 gen{random_device{}()};

public:
    void random_select(vector<vector<int>>& points, int left, int right, int K) {
        int pivot_id = uniform_int_distribution<int>{left, right}(gen);
        int pivot = points[pivot_id][0] * points[pivot_id][0] + points[pivot_id][1] * points[pivot_id][1];
        swap(points[right], points[pivot_id]);
        int i = left - 1;
        for (int j = left; j < right; ++j) {
            int dist = points[j][0] * points[j][0] + points[j][1] * points[j][1];
            if (dist <= pivot) {
                ++i;
                swap(points[i], points[j]);
            }
        }
        ++i;
        swap(points[i], points[right]);
        // [left, i-1] 都小于等于 pivot, [i+1, right] 都大于 pivot
        if (K < i - left + 1) {
            random_select(points, left, i - 1, K);
        }
        else if (K > i - left + 1) {
            random_select(points, i + 1, right, K - (i - left + 1));
        }
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = points.size();
        random_select(points, 0, n - 1, K);
        return {points.begin(), points.begin() + K};
    }
};