class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int minVal = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            int curVal = prices[i];
            if(curVal > minVal) {
                maxPro += (curVal-minVal);
                
            }
            minVal = curVal;

        }

        return maxPro;
    }
};