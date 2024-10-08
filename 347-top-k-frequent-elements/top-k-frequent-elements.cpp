class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i : nums) mp[i]++;
        priority_queue<pair<int, int>> pq;

        for(auto it: mp) {
            pq.push({it.second, it.first});
        }

        vector<int> ans;
        while(k) {
            int x = pq.top().second;
            pq.pop();
            ans.push_back(x);
            k--;
        }

        return ans;
    }
};