class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1)/2;
        
        return sum - accumulate(nums.begin(), nums.end(), 0);
        // for(int i = 0; i < n; i++){
        //     sum -= nums[i];
        // }
        // return sum;
    }
};