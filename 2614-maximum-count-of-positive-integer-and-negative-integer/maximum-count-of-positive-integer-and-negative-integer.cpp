class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;

        for(int i : nums) {
            if(i < 0) neg++;
            if(i > 0) pos++;
        }

        return max(neg, pos);
    }
};