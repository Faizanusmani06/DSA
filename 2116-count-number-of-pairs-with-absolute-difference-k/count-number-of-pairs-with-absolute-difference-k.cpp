class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int ans = 0;
        int n = nums.size();

        int cnt = 0;
        for(int i = n-1; i >= 0; i--) {
            if(mp[nums[i] + k]) cnt += mp[nums[i]+k];
            if(mp[nums[i] - k]) cnt += mp[nums[i]-k];
            mp[nums[i]]++;
        }

        return cnt;
    }
};