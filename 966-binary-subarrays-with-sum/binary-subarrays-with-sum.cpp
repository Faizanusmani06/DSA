class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int sum = nums[i];
            for(int j = i; j < n; j++) {
                if(i != j) sum += nums[j];
                if(sum == goal) cnt++;
            }
        }

        return cnt;
    }
};