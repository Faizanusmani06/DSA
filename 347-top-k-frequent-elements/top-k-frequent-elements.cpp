class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp1;
        vector<int> ans;
        for(int i : nums) mp1[i]++;
        map<int, int> mp2;
        for(auto a: mp1) {
            mp2[a.second] = a.first;
        }

        vector<pair<int, int>> arr;
        for(auto a: mp1) {
            arr.push_back({a.second, a.first});
        }
        sort(arr.rbegin(), arr.rend());

        for(int i = 0; i < k; i++) ans.push_back(arr[i].second);
       
        return ans;
    }
};