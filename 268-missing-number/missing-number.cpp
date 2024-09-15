class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ourSum = 0, n = nums.size();

        for(int i: nums) ourSum += i;

        return n*(n+1)/2 - ourSum;
    }
};