class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        map<int, int> mp;
        int curSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            int rem = (((curSum)%k)+k)%k;
            mp[rem]++;
        }
        int result = 0;
        for(int i = 0; i < k; i++) {
            int freq = mp[i];
            if(freq > 1) result += (freq)*(freq-1)/2;
        }

        result += mp[0];
        return result; 
    }
};