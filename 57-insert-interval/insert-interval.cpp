class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int n = intervals.size();
        if(!n) return {newInterval};
        if(intervals[n-1][1] < newInterval[0]) {
            intervals.push_back(newInterval);
            return intervals;
        }
        if(intervals[0][0] > newInterval[1]) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        int  i;

        for(i = 0; i < n; i++) {
            if(newInterval[0] < intervals[i][0]) {
                if(i-1>=0)
                    if(newInterval[0] <= intervals[i-1][1])i--;
                break;
            }
            if(newInterval[0] == intervals[i][0]) {
                break;
            }
        }

        int stInd = i==n?(n-1):i, j;
        if(i == -1) stInd = 0;
        
        for(j = stInd; j < n; j++) {
            if(newInterval[1] < intervals[j][0]) {
                j--;
                break;
            }
            if(newInterval[1] == intervals[j][0]) {
                break;
            }
        }
   
        int ltInd = j==n?(n-1):j;
        if(j == -1) ltInd = 0;
        cout << stInd << " " << ltInd << endl;
        if(ltInd < n) {
            int st = min(intervals[stInd][0], newInterval[0]);
            int en = max(intervals[ltInd][1], newInterval[1]);
            intervals.erase(intervals.begin()+stInd, intervals.begin() + ltInd + 1);
            intervals.insert(intervals.begin()+stInd, {st, en});
            
        }else intervals.insert(intervals.begin()+stInd, newInterval);
        
        return intervals;
    }
};