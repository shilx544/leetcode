class Solution {
public:
    // 4 direction
    const int dx[4] = {1, 0, 0, -1};
    const int dy[4] = {0, 1, -1, 0};
    // 广度优先搜索
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int curColor = image[sr][sc];
        if (newColor == image[sr][sc]) {
            return image;
        }
        
        int m = image.size();
        int n = image[0].size();
        image[sr][sc] = newColor;
        queue<pair<int, int>> que;
        que.emplace(sr, sc);
        while (!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            for (int i = 0; i < 4; ++i) {
                int mx = x + dx[i], my = y + dy[i];
                if (mx >= 0 && mx < m && my >=0 && my < n && image[mx][my] == curColor) {
                    que.emplace(mx,my);
                    image[mx][my] = newColor;
                }
            }
        }
        return image;
    }

    // 深度优先搜索
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
    } 
};