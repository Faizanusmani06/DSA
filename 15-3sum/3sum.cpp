class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        if(n < 3) return {};
        for(int i = 0; i < n-2; i++) {

            int j = i+1;
            int k = n-1;

            while(j < k) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    ans.insert({nums[i], nums[j], nums[k]});
                    j++;
                }
                else if(nums[i] + nums[j] + nums[k] < 0) j++;
                else k--;
            }
        }

        vector<vector<int>> res;

        for(auto it : ans) res.push_back(it);

        return res;
    }
};