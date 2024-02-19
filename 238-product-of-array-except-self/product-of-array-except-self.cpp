class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int n = nums.size();
        int cntZeroes = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i]) {
                prod *= nums[i];
            }else cntZeroes++;
        }

        vector<int> ans;

        for(int i = 0; i < n; i++) {
            if(cntZeroes == 0) ans.push_back(prod/nums[i]);
            else if(cntZeroes == 1 && nums[i] != 0) ans.push_back(0);
            else if(cntZeroes == 1 && nums[i] == 0) ans.push_back(prod);
            else ans.push_back(0);
        }

        return ans;
    }
};