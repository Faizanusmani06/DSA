class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> roomCnt(n, 0);

        set<int> s;

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        sort(meetings.begin(), meetings.end());

        int m = meetings.size();

        for(int i = 0; i < n; i++) {
            s.insert(i);
        }

        for(int i = 0; i < m; i++) {
            long long start = meetings[i][0];
            long long end = meetings[i][1];

            while(pq.size() > 0 && pq.top().first <= start) {
                int room = pq.top().second;
                pq.pop();
                s.insert(room);
            }

            if(!s.size()) {
                pair<long long, long long> p = pq.top();
                pq.pop();
                long long diff = end - start;
                start = p.first;
                end = start + diff;
                s.insert(p.second);
            }

            auto it = s.begin();
            roomCnt[*it]++;

            pq.push({end, *it});
            s.erase(*it);
        }

        int ans = 0;
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            if(maxi < roomCnt[i]) {
                maxi = roomCnt[i];
                ans = i;
            }
        }

        return ans;

    }
};