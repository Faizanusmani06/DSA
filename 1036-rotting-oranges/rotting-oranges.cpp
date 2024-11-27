class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();

        int total_oranges = 0, total_rotten = 0, days = 0;

        // cordinates of rotten oranges

        queue<pair<int, int>> rotten;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0)
                    total_oranges++;
                if (grid[i][j] == 2)
                    rotten.push({i, j});
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while (!rotten.empty()) {
            int k = rotten.size();
            total_rotten += k;

            while (k--) {
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();

                for (int t = 0; t < 4; t++) {
                    int adjRow = x + drow[t];
                    int adjCol = y + dcol[t];

                    if (adjRow < 0 || adjRow >= m || adjCol < 0 ||
                        adjCol >= n || grid[adjRow][adjCol] != 1)
                        continue;
                    grid[adjRow][adjCol] = 2;
                    rotten.push({adjRow, adjCol});
                }
            }

            if (!rotten.empty())
                days++;
        }

        return total_oranges == total_rotten ? days : -1;
    }
};