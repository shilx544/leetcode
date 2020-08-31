class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if (rooms.empty()) {
            return false;
        }
        int n = rooms.size();
        vector<bool> isOpen(n, false);
        isOpen[0] = true;

        queue<int> que;
        for (int i = 0; i < rooms[0].size(); ++i) {
            que.push(rooms[0][i]);
            isOpen[rooms[0][i]] = true;
        }

        while (!que.empty()) {
            int number = que.front();
            que.pop();
            isOpen[number] = true;
            for (int i = 0; i < rooms[number].size(); ++i) {
                if (isOpen[rooms[number][i]] == false) {
                    que.push(rooms[number][i]);
                }

            }
        }

        for (auto b:isOpen) {
            if (b == false) {
                return false;
            }
        }
        return true;
    }
};