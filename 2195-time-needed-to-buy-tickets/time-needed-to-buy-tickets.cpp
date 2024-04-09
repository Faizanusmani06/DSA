class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;

        int val = tickets[k];

        for(int i = 0; i < tickets.size(); i++) {
            if(i <= k) {
                ans += min(tickets[i], val);
            }else {
                ans += min(tickets[i], val-1);
            }
        }

        return ans;
    }
};