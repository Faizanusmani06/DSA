class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mp;
        for(int i : nums1) {
            mp[i]++;
        }

        vector<int> ans;
        for(int i : nums2) {
            if(mp.find(i) != mp.end()) {
                ans.push_back(i);
                mp.erase(i);
            }
        }

        return ans;
    }
};