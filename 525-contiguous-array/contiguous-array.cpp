class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        int preSum = 0;
        int len = 0;

        for(int i = 0; i < nums.size(); i++) {
            preSum += (nums[i]==0 ? -1 : 1);
            if(preSum == 0) {
                len = i + 1;
            }else if(mp.find(preSum) != mp.end()) {
                len = max(len, i - mp[preSum]);
            }else mp[preSum] = i;
        }

        return len;
    }
};