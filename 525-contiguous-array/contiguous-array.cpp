class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = 0;

        map<int, int> mp;
        int curSum = 0;

        for(int i = 0; i < nums.size(); i++) {
            curSum += nums[i]==1?1:-1;

            if(curSum == 0) {
                len = i+1;
            }else if(mp.find(curSum) != mp.end()) {
                len = max(len, i - mp[curSum]);
            } else mp[curSum] = i;
        }

        return len;
    }
};