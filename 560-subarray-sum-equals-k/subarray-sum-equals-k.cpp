class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0, sum = 0;
        map<int, int> mp;

        for(int i : nums) {
            sum += i;

            if(sum == k) cnt++;

            if(mp.find(sum - k) != mp.end()) cnt += mp[sum - k];

            mp[sum]++;
        }

        return cnt;
    }
};