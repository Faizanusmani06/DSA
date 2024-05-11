class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(), nums.end());

        int n = nums.size(), i, j;
        // pivot element 
        for(i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1])
                break;
        }
        if(i < 0) reverse(nums.begin(), nums.end());

        else {
            for(j = n-1; j > i; j--) {
                if(nums[j] > nums[i]) break;
            }
            swap(nums[i], nums[j]);

            // minimise the suffix
            reverse(nums.begin()+i+1, nums.end());
        }
    }
};