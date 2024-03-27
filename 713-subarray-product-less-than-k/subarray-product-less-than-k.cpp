class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int sum = nums[i];

            for(int j = i; j < n; j++) {

                if(i!=j) sum*=nums[j];
                if(sum < k) cnt++;
                else break;
            }
        }

        return cnt;
    }
};