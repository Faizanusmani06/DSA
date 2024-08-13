class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        if(n<3 || nums[0] > 0) return {};

    
        for(int i = 0; i < n-2; i++) {
            if(nums[i] > 0) break;
            int j = i+1;
            int k = n-1;

            if(i>0 && nums[i] == nums[i-1]) continue;
            while(j < k) {
                int curSum = nums[i] + nums[j] + nums[k];
                if(curSum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    int last_j = nums[j];
                    int last_k = nums[k];

                    while(j < k && last_j == nums[j]) j++;
                    while(j < k && last_k == nums[k]) k--;
                }
                else if(curSum > 0) k--;
                else j++;
            }

        }
        
        return ans;
    }
};