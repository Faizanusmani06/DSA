class Solution {
    int solve(vector<int> &nums, int st, int end) {
        int prev1 = nums[st];
        int prev2 = 0;

        for(int i = st+1; i <= end; i++) {
            int pick = nums[i] + prev2;
            int notPick = 0 + prev1;
            int curr = max(pick, notPick);

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(solve(nums, 0, n-2), solve(nums, 1, n-1));
    }
};