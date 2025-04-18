class Solution {

public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i;
        for (i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1])
                break;
        }

        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int j = n - 1; j >= 0; j--) {
            if (nums[j] > nums[i]) {
                swap(nums[i], nums[j]);
                break;
            }
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};