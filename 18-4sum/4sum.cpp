

class Solution {

long long mod = LLONG_MAX;
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n < 4) return {};
        for(int i = 0; i < n-3; i++) {
            for(int j = i+1; j < n-2; j++) {
                int k = j+1;
                int l = n-1;

                while(k < l) {
                    long long curSum = ((((nums[i] + nums[j]) % mod + nums[k]) % mod) % mod + nums[l]) % mod;

                    if(curSum == target) {
                        ans.insert({nums[i],  nums[j], nums[k], nums[l]});
                        k++;
                    }else if(curSum < target) k++;
                    else l--;
                }
            }
        }

        vector<vector<int>> res;

        for(auto i: ans) {
            res.push_back(i);
        }

        return res;
    }
};