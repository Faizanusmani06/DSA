class Solution {
private:
    int f(int ind, vector<int> &arr, int k, int n, vector<int> &dp) {
        if(ind == n) return 0;
        int len = 0, maxi = INT_MIN, maxele = INT_MIN, sum = 0;
        if(dp[ind] != -1) return dp[ind];
        for(int i = ind; i < min(ind + k, n); i++) {
            len++;
            maxele = max(maxele, arr[i]);

            int sum = maxele * len + f(i + 1, arr, k, n, dp);
            maxi = max(maxi, sum);
        }
        return dp[ind] = maxi;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        dp[n] = 0;
        for(int ind = n-1; ind >= 0; ind--) {
            int len = 0, maxi = INT_MIN, maxele = INT_MIN, sum = 0;
            if(dp[ind] != -1) return dp[ind];
            for(int i = ind; i < min(ind + k, n); i++) {
                len++;
                maxele = max(maxele, arr[i]);

                int sum = maxele * len + dp[i+1];
                maxi = max(maxi, sum);
            }

            dp[ind] = maxi;
        }
        return dp[0];
        
    }
};
