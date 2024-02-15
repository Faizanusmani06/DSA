// 2971. Find Polygon With the Largest Perimeter

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int i;
        if(nums.size() < 3) return -1;

        long long sum = 0;
        long long ans = -1;

        sort(nums.begin(), nums.end());
        
        for(i = 0; i < nums.size(); i++) {

            if(sum > nums[i]) {
                sum += nums[i];
                ans = max(sum, ans);
            }
            else {
                sum += nums[i];
            }
        }
    
        return ans;
    }
};
