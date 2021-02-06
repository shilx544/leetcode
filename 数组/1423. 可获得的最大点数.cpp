class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for (auto point : cardPoints) {
            sum += point;
        }
        int remain = n - k;
        int min = 0;
        for (int i = 0; i < remain; ++i) {
            min += cardPoints[i];
        }
        int base = min;
        for (int i = remain; i < n; ++i) {
            base = base + cardPoints[i] - cardPoints[i-remain];
            min = base < min ? base : min;
        }
        return sum-min;
    }
};

// ----------------------------------------------------------------
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        // 滑动窗口大小为 n-k
        int windowSize = n - k;
        // 选前 n-k 个作为初始值
        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + windowSize, 0);
        int minSum = sum;
        for (int i = windowSize; i < n; ++i) {
            // 滑动窗口每向右移动一格，增加从右侧进入窗口的元素值，并减少从左侧离开窗口的元素值
            sum += cardPoints[i] - cardPoints[i - windowSize];
            minSum = min(minSum, sum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - minSum;
    }
};