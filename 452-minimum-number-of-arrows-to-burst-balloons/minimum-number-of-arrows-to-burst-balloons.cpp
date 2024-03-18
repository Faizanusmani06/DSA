class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        for(auto it : points) {
            cout << it[0] << " " << it[1] << endl;
        }
        int ans = 1;
        int val = points[0][1];
        for(int i = 1; i < points.size(); i++) {
            int st = points[i][0];
            int end = points[i][1];

            if(val >= st && val <= end) continue;
            else if(val >= st && val > end) val = end;
            else {
                val = end;
                ans++;
            }
        }

        return ans;
    }
};