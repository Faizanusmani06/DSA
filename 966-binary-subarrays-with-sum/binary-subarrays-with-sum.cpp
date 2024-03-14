class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> count;
        count[0] = 1;

        int curSum = 0;
        int cnt = 0;

        for(int i : nums) {
            curSum += i;
            if(count.find(curSum-goal) != count.end()) {
                cnt += count[curSum-goal];
            }
            count[curSum]++;
        }
        return cnt;
    }
};