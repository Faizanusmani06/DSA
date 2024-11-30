class Solution {
private:
    bool dfs(int node, int c, vector<int>& color,  vector<vector<int>>& graph) {
        color[node] = c;

        for(auto adj: graph[node]) {
            if(color[adj] == -1) {
                if(!dfs(adj, !c, color, graph)) return false;
            }
            else if(color[adj] == c) return false;
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();

        vector<int> color(v, -1);

        for(int i = 0; i < v; i++) {
            if(color[i] == -1) {
                if(!dfs(i, 0, color, graph)) return false;
            }
        }
        return true;
    }
};