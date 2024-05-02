class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int, int> mp;
        for(int i : nums) mp[i]++;

        int ans = -1;

       for(auto it: mp) {
            if(mp.find(-it.first) != mp.end()) ans = it.first;
        
        }
        return ans;
    }
};