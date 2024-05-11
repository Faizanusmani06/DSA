class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int col0 = 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!matrix[i][j]) {
                    // marks 0th column
                    matrix[i][0] = 0;

                    // marks 0th row
                    if(j!=0) {
                        matrix[0][j] = 0;
                    }else col0 = 0;
                }
            }
        }

        // marks matrix from (1, 1) to (m-1, n-1)

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(!matrix[0][0]) {
            for(int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        if(!col0) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};