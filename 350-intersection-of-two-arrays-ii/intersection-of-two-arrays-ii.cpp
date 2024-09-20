class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        map<int, int> mp;

        for(int i : nums1) {
            mp[i]++;
        }

        for(int i : nums2) {
            if(mp.find(i) != mp.end()) {
                ans.push_back(i);
                mp[i]--;
                if(mp[i] == 0) mp.erase(i);
            }
            
        }

        return ans;
    }
};