class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < score.size(); i++) pq.push({score[i], i});
        vector<string> ans(score.size());
        int rank = 1;
        while(!pq.empty()) {
            pair <int, int> it = pq.top();
            pq.pop();

            int ind = it.second;

            if(rank == 1) {
                ans[ind] = "Gold Medal";
            }else if (rank == 2) {
                ans[ind] = "Silver Medal";
            }else if(rank == 3) {
                ans[ind] = "Bronze Medal";
            }else {
                ans[ind] = to_string(rank);
            }
            rank++;
        }

        return ans;
    }
};