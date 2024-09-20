class Solution {
    int solve(vector<int> &nums, int x) {
        int n = nums.size();
        int low = 0, high = n-1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] >= x) high = mid - 1;
            else low = mid + 1;
        }

        if(high >= 0) return n-high-1;
        else return n;

        
    }
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();


        int low = 0, high = n;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int cnt = solve(nums, mid);

            if(mid == cnt) return mid;
            else if(mid > cnt) high = mid - 1;
            else low = mid + 1;
        }

        return -1;


    }
};