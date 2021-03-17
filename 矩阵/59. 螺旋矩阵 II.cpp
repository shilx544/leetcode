class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int i = 0, j = 0;
        //记录四种不同移动状态
        int state = 0;
        int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int k = 1; k <= n*n; ++k) {
            //遇到边界或者已经赋值过的节点则回到上一节点位置并更新移动状态
            if(i==n||j==n||i==-1||j==-1||result[i][j]) {
                i-=move[state][0];
                j-=move[state][1];
                state=(state+1)%4;
                i+=move[state][0];
                j+=move[state][1];
            }
            result[i][j]=k;
            i+=move[state][0];
            j+=move[state][1];
        }
        return result;
    }
};