class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> mp;

        for(int i: nums) mp[i]++;

        for(auto it: mp) {
            if(it.second > 1) return true;
        }

        return false;
    }
};