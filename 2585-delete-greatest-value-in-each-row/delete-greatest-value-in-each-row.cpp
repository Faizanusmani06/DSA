class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++) {
            sort(grid[i].rbegin(), grid[i].rend());
        }

        int ans = 0;

        for(int j = 0; j < n; j++) {
            int maxEle = INT_MIN;
            for(int i = 0; i < m; i++) {
                maxEle = max(maxEle, grid[i][j]);
            }
            ans += maxEle;
        }
        return ans;
    }
};