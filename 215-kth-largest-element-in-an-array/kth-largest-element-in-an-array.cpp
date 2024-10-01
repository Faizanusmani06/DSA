class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(k > nums.size()) return -1;
        priority_queue<int> pq;

        for(int i : nums) {
            pq.push(i);
        }

        while(k > 1) {
            pq.pop();
            k--;
        }

        return pq.top();
    }
};