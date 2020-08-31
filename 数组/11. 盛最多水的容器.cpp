class Solution {
public:
    int maxArea(vector<int>& height) {
       int n = height.size();
       int result = 0;
       if (height.size() < 2) {
           return result;
       }
       int leftMax = height[0];
       for (int i = 0; i < n; ++i) {
           if (height[i] < leftMax) {
               continue;
           } else if (height[i] > leftMax) {
               leftMax = height[i];
           }
            int rightMax = 0;
            for (int j = n-1; j > i; --j) {
               if (height[j] < rightMax){
                   continue;
               } else if (height[j] > rightMax) {
                   rightMax = height[j];
               }
               int area = (j-i) * min(height[i], height[j]);
               result = area > result ? area : result;
           }
       }
       return result;
    }
};