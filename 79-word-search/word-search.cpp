class Solution {
    int n, m, s;
    vector<vector<int>> visited;
    bool dfs(int i, int j, int k, vector<vector<char>>& board, string word) {
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || board[i][j] != word[k]) return 0;

        if(k == s-1) return true;

        visited[i][j] = 1;

        bool a1 = dfs(i+1, j, k+1, board, word);
        bool a2 = dfs(i, j+1, k+1, board, word);
        bool a3 = dfs(i-1, j, k+1, board, word);
        bool a4 = dfs(i, j-1, k+1, board, word);

        visited[i][j] = 0;

        return a1 || a2 || a3 || a4;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        visited.assign(m, vector<int>(n, 0));
        s = word.size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(i, j, 0, board, word)) return 1;
                }
            }
        }

        return 0;
    }
};