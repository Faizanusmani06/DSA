class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq1;
        for(int i = 0; i < nums.size(); i++) {
            pq1.push({nums[i], i});
            if(pq1.size() > k) pq1.pop();
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq2;

        while(!pq1.empty()) {
            pq2.push({pq1.top().second, pq1.top().first});
            pq1.pop();
        }

        vector<int> ans;

        while(!pq2.empty()) {
            ans.push_back(pq2.top().second);
            pq2.pop();
        }

        return ans;


    }
};