class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<int>& vis) {
        vis[node] = 1;

        for(int x: adj[node]) {
            if(!vis[x]) {
                dfs(x, adj, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> adj[n];
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j]  && i!=j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis);
                cnt++;
            }
        }
        return cnt;
    }
};