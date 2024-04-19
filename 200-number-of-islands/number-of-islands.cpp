class Solution {
private:
    void dfs(vector<vector<char>> &arr, int i, int j, int m, int n) {
        if(i < 0 || i >= m || j < 0 || j >= n || arr[i][j] == '0') return;

        arr[i][j] = '0';

        dfs(arr, i+1, j, m, n);
        dfs(arr, i-1, j, m, n);
        dfs(arr, i, j+1, m, n);
        dfs(arr, i, j-1, m, n);


    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        if(m == 0 || n == 0) return 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return ans;
    }
};