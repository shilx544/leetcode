class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            return lineCheck(board) && rowCheck(board) && zoneCheck(board);
        }
    
        bool lineCheck(vector<vector<char>>& board) {
            for (auto v : board) {
                unordered_set<char> filter;
                for (auto c : v) {
                    if (c == '.') continue;
                    auto it = filter.find(c);
                    if (it != filter.end()) {
                        return false;
                    }
                    filter.insert(c);
                }
            }
            return true;
        }
    
        bool rowCheck(vector<vector<char>>& board) {
            for (int i = 0; i < board.size(); ++i) {
                unordered_set<char> filter;
                for (int j = 0; j < board[i].size(); ++j) {
                    if (board[j][i] == '.') continue;
                    auto it = filter.find(board[j][i]);
                    if (it != filter.end()) {
                        return false;
                    }
                    filter.insert(board[j][i]);
                }
            }
            return true;
        }
    
        bool zoneCheck(vector<vector<char>>& board) {
            int checkSize = 3;
            for (int n = 0; n < checkSize; ++n) {
                for (int m = 0; m < checkSize; ++m) {
                    unordered_set<char> filter;
                    for (int i = 3*n; i < 3*n + 3; ++i) {
                        for (int j = 3*m; j < 3*m + 3; ++j) {
                            if (board[i][j] == '.') continue;
                            auto it = filter.find(board[i][j]);
                            if (it != filter.end()) {
                                return false;
                            }
                            filter.insert(board[i][j]);
                        }
                    }
                }
            }
            return true;
        }
    };