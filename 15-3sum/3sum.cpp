class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        if(n < 3 || nums[0] > 0) return {};

        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) break;

            if(i>0 && nums[i] == nums[i-1]) continue;


            int l = i+1, r = n-1;
            int sum = 0;
            while(l < r) {
                sum = nums[i] + nums[l] + nums[r];

                if(sum > 0) r--;
                else if(sum < 0) l++;
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    int last_l = nums[l], last_r = nums[r];

                    while(l < r && nums[l] == last_l) l++;
                    while(l < r && nums[r] == last_r) r--;
                }
            }
        }

        return ans;
    }
};