class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        dp[0] = nums[0];
        int prev1 = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++) {

            int pick = nums[i] + prev2;
            int notPick = 0 + prev1;
            dp[i] = max(pick, notPick);

            prev2 = prev1;
            prev1 = dp[i];
        }
        return prev1;
    }
};