// Subarrays with exactly K different integers = (subarray with atmost k different integers) - (subarray with atmost k-1 different integers)

class Solution {
public:
    int solve(vector<int> &nums, int k) {
        unordered_map<int,int>mp;
        int left = 0, right = 0, ans = 0;

        while(right < nums.size()) {
            mp[nums[right]]++;

            while(k < mp.size()) {
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) mp.erase(nums[left]);
                left++;
            }

            ans += (right-left+1);
            right++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int k1 = solve(nums, k);
        cout << k1;
        int k2 = solve(nums, k-1);
        cout << k2;
        return k1-k2;
    }
};