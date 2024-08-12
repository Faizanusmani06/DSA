class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(!nums.size()) return {};
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            int valAtInd = nums[abs(nums[i]) - 1];
            if(valAtInd < 0) ans.push_back(abs(nums[i]));

            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
        return ans;
    }
};