const int N = 1e5;
vector<vector<int>> g;
vector<bool> visited;

int countConnectedNodes (int src) {
    if(visited[src]) return 0;
    visited[src] = true;

    int result = 1;

    for(auto i : g[src]) result += countConnectedNodes(i);
    return result;
}
class Solution {
    vector<int> sieve;

    void buildSieve() {
        sieve.resize(N+1);
        for(long j = 2; j <= N; j++) {
            if(sieve[j] != 0) continue;
            sieve[j] = j;

            for(long k = j*j; k <= N; k +=j) {
                if(!sieve[k]) sieve[k] = j;
            }

        }
    }
    vector<int> primeFactors (int x) {
        vector<int> result;
        while(x != 1) {
            int f = sieve[x];
            while(x % f == 0) x /= f;
            result.push_back(f);
        }

        return result;
    }
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        vector<int> val(N+1, -1);

        buildSieve();
        int n = nums.size();
        if(n==1) return true;
        g.clear();
        g.resize(n);

        visited.clear();
        visited.resize(n);

        for(int j = 0; j < n; j++) {
            if(nums[j] == 1) return false;

            vector<int> primes = primeFactors(nums[j]);

            for(auto p : primes) {
                if(val[p] != -1) {
                    g[j].push_back(val[p]);
                    g[val[p]].push_back(j);

                }
                val[p] = j;
            }
        }

        if(countConnectedNodes(0) == n) return true;
        return false;
    }
};