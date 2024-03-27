class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size();
        int cnt = 0;
        int left = 0, right = 0, prod = 1;

        while(right < n) {
            prod *= nums[right];
            while(prod >= k) prod /= nums[left++];
            cnt += (1 + right - left);
            right++;
        }

        return cnt;
    }
};