class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int s = nums.size();
        if (s < 3)
            return {};

        for (int i = 0; i < s - 2; i++) {
            if (nums[0] > 0)
                break;

            int j = i + 1, k = s - 1;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if(sum == 0) {
                    ans.push_back({nums[i], nums[j++], nums[k--]});

                    while(j < s && nums[j] == nums[j-1]) j++;
                    while(k >= 0 && nums[k] == nums[k+1]) k--;

                }else if(sum < 0) j++;
                else k--;
            }
        }

        return ans;
    }
};