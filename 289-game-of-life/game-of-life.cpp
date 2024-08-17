class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> dummy = board;
        

        int m = board.size();
        int n = board[0].size();
        int r[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int c[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int cnt = 0;
                for(int k = 0; k < 8; k++) {
                    int rows = i + r[k];
                    int cols = j + c[k];
        
        
                    if((rows >= 0 && rows < m) && (cols >= 0 && cols < n) && dummy[rows][cols] == 1 )  cnt++;

                }
                if(dummy[i][j] && cnt < 2) board[i][j] = 0;
                else if(dummy[i][j] && (cnt == 2 || cnt == 3)) board[i][j] = 1;
                else if(dummy[i][j] && cnt > 3) board[i][j] = 0;
                else if(!dummy[i][j] && cnt == 3) board[i][j] = 1;
            }
        }
    }
};