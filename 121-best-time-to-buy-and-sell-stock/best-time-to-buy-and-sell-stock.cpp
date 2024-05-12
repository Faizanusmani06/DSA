class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < curr) curr = prices[i];
            else maxProfit = max(maxProfit, prices[i]-curr);  
        }

        return maxProfit;
    }
};