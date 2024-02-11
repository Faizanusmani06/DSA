class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> ans = matrix;
        vector<int> col(n, 0);
        for(int j = 0; j < n; j++) {
            int max_value = INT_MIN;
            for(int i = 0; i < m; i++) {
                max_value = max(max_value, matrix[i][j]);
            }
            col[j] = max_value;
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(ans[i][j] == -1) {
                    ans[i][j] = col[j];
                }
            }
        }
        
        return ans;
    }
};
