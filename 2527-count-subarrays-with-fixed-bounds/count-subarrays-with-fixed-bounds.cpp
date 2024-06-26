class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long cnt = 0;
        int out = -1, left = -1, right = -1;

        for(int i = 0; i < nums.size(); i++) {
            if(!(nums[i] >= minK && nums[i] <= maxK)) out = i;
            if(nums[i] == minK) left = i;
            if(nums[i] == maxK) right = i;

            cnt += max(0, min(left, right) - out);
        }
        return cnt;
    }
};