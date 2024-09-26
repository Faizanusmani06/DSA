class Solution {
 
    
    bool dfs(int i, int j, int k, vector<vector<char>>& board, string word, vector<vector<int>> &visited, int s, int m, int n) {
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || board[i][j] != word[k]) return 0;

        if(k == s-1) return true;

        visited[i][j] = 1;



        bool a1 = dfs(i+1, j, k+1, board, word, visited, s, m, n);
        bool a2 = dfs(i, j+1, k+1, board, word, visited, s, m, n);
        bool a3 = dfs(i-1, j, k+1, board, word, visited, s, m, n);
        bool a4 = dfs(i, j-1, k+1, board, word, visited, s, m, n);

        visited[i][j] = 0;

        return a1 || a2 || a3 || a4;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));
        int s = word.size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(i, j, 0, board, word, visited, s, m, n)) return 1;
                }
            }
        }

        return 0;
    }
};