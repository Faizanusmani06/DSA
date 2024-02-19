class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp1;
        vector<int> ans;
        for(int i : nums) mp1[i]++;

        // vector<pair<int, int>> arr;
        // for(auto a: mp1) {
        //     arr.push_back({a.second, a.first});
        // }
        // sort(arr.rbegin(), arr.rend());

        // for(int i = 0; i < k; i++) ans.push_back(arr[i].second);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(auto i: mp1) {
            minHeap.push({i.second, i.first});
            if(minHeap.size() > k) minHeap.pop();
        }

        while(k--) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
       
        return ans;
    }
};