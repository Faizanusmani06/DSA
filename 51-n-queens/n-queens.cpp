class Solution {

    void solve(int col, vector<string>& board, vector<vector<string>>& ans,
               int n, vector<int>& rowArr, vector<int>& upperDia,
               vector<int>& lowerDia) {
   
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (!rowArr[row] && !upperDia[n - 1 - row + col] &&
                !lowerDia[row + col]) {

                board[row][col] = 'Q';
                rowArr[row] = 1;
                upperDia[n - 1 - row + col] = 1;
                lowerDia[row + col] = 1;
                solve(col + 1, board, ans, n, rowArr, upperDia, lowerDia);
                board[row][col] = '.';
                rowArr[row] = 0;
                upperDia[n - 1 - row + col] = 0;
                lowerDia[row + col] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);

        string str(n, '.');
        for (int i = 0; i < n; i++)
            board[i] = str;
        vector<int> rowArr(n, 0), upperDia(2 * n - 1, 0),
            lowerDia(2 * n - 1, 0);
        solve(0, board, ans, n, rowArr, upperDia, lowerDia);
        return ans;
    }
};