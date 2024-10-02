class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
            int n = mp[nums[i]].size();
           
            if(n >= 2 && (mp[nums[i]][n-1] - mp[nums[i]][n-2]) <= k) return true;
        }
        return false;
    }
};