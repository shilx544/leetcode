class Solution {
private:
    // 4 direction
    const int dx[4] = {1, 0, 0, -1};
    const int dy[4] = {0, 1, -1, 0};
    bool dfs(vector<vector<char>>& board, string& word, int x, int y, int index) {
        if (board[x][y] != word[index]) {
            return false;
        }
        
        if (word.size()-1 == index) {
            return true;
        }

        char c = board[x][y];
        board[x][y] = '0';
        index++;

        if((x > 0 && dfs(board, word, x - 1, y, index)) // 往上走 (此处多谢笑川兄指正)
        || (y > 0 && dfs(board, word, x, y - 1, index)) // 往左走
        || (x < board.size() - 1 && dfs(board, word, x + 1, y, index)) // 往下走
        || (y < board[0].size() - 1 && dfs(board, word, x, y + 1, index))){ // 往右走
            return  true; // 其中一条能走通，就算成功
        }
        board[x][y] = c;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty()) {
            return false;
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};