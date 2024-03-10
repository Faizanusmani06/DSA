class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int ans1 = 0, ans2 = 0;
        unordered_map<int, int>mp;

        for(int i : nums1) mp[i]++;
        for(int j : nums2) if(mp[j]) ans1++;
        mp.clear();
        for(int i : nums2) mp[i]++;
        for(int j : nums1) if(mp[j]) ans2++;

        return {ans2, ans1};
    }
};