class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> result;
        vector<vector<int>> used(R, vector(C, 0));

        queue<pair<int, int>> q;

        int ax[] = {1, 0, -1, 0};
        int ay[] = {0, 1, 0, -1};

        q.push(pair<int, int>(r0, c0));
        used[r0][c0] = 1;

        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            result.push_back({p.first, p.second});

            for (int i = 0; i < 4; ++i) {
                int newx = p.first + ax[i];
                int newy = p.second + ay[i];
                if (newx >= 0 && newy >= 0 && newx < R && newy < C && used[newx][newy] == 0) {
                    q.push(pair<int, int>(newx, newy));
                    used[newx][newy] = 1;
                }
            }
        }
        return result;
    }
};