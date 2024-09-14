class Solution {
public:
    int mod = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;
        int i = 0, j = n-1;
        sort(nums.begin(), nums.end());

        vector<int> arr(n);

        arr[0] = 1;

        for(int i = 1; i < n; i++) {
            arr[i] = (arr[i-1] * 2) % mod;
        }

        while(i <= j) {
            if(nums[i] + nums[j] <= target) {
                cnt += arr[j-i];
                cnt %= mod;
                i++;
            }else j--;
        }


        return cnt;
    }
};