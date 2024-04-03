
class Solution {
public:
    int n, m, s;
    vector<vector<bool>> visited; 
    bool dfs (int i, int j, int k, vector<vector<char>>& board, string& word)
    {
        if (i < 0 || i >= n || j < 0 || j >= m ||
        visited[i][j] || board[i][j] != word[k])
            return 0;
        if (k == s-1)
            return 1;
        visited[i][j] = 1;
        bool a1 = dfs(i + 1, j, k + 1, board, word);
        bool a2 = dfs(i, j + 1, k + 1, board, word);
        bool a3 = dfs(i - 1, j, k + 1, board, word);
        bool a4 = dfs(i, j - 1, k + 1, board, word);
        visited[i][j] = 0; 
        return a1 || a2 || a3 || a4;
    }

    bool exist(vector<vector<char>>& board, string& word) {
        n = board.size();
        m = board[0].size();
        s = word.size();
        visited.assign(n, vector<bool>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 0, board, word)) return 1;
                }
            }
        }
        return 0;
    }
};

