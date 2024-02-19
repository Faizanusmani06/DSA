class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        sort(nums.begin(), nums.end());
        int ans = 1;
        int x = 1;
        for(int i = 0; i < nums.size()-1; i++) {
            if((nums[i+1] - nums[i]) == 1) x++;
            else if(nums[i+1] == nums[i]) continue;
            else {
                ans = max(ans, x);
                x = 1;
            }
        }

        ans = max(ans, x);

        return ans;
    }
};