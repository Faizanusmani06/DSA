class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i, j;
        int n = nums.size();
        vector<int> ans;
        for(i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0) break;
        }

        j = i-1;

        while(i < n || j >= 0) {
            if(i < n && j >= 0) {
                if(abs(nums[i]) < abs(nums[j])) {
                    ans.push_back(pow(nums[i++], 2));
                }else {
                    ans.push_back(pow(nums[j--], 2));
                }
            }else {
                if(i < n)ans.push_back(pow(nums[i++], 2));
                else ans.push_back(pow(nums[j--], 2));
            }
        }

        return ans;
    }
};