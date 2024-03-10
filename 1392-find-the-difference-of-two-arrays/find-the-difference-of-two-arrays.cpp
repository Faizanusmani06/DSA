class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans(2);

        unordered_map<int, int>mp1;
        for(int i : nums2) mp1[i]++;
        unordered_map<int, int>mp2;
        for(int i : nums1) mp2[i]++;

        for(auto i : mp1) {
            if(!mp2[i.first]) ans[1].push_back(i.first);
        }
        for(auto i : mp2) {
            if(!mp1[i.first]) ans[0].push_back(i.first);
        }
        return ans;
        
    }
};