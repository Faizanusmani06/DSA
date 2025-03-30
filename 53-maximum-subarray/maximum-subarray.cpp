class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int maxSum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];

            if(sum < 0) sum = 0;

            maxSum = max(maxSum, sum);
        }
        if(maxSum == 0) return *max_element(nums.begin(), nums.end());
        return maxSum;
    }
};