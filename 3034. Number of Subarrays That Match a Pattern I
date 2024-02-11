class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int m = nums.size();
        int n = pattern.size();
        int i = 0, j = 0;
        int cnt = 0;
        while(i < m-1) {
            
            if(pattern[j] == 0) {
                if(nums[i] == nums[i+1]) {
                    i++;
                    if(j==n-1) {
                        i = i-j;
                        j=0;
                        cnt++;
                    }else j++;
                    
                }
                else {
                    i = i-j+1;
                    j = 0;
                }
            }
            else if(pattern[j] == 1) {
                if(nums[i] < nums[i+1]) {
                    i++;
                    if(j==n-1) {
                        i = i-j;
                        j=0;
                        cnt++;
                    }
                    else j++;
                    
                }
                else {
                    i = i-j+1;
                    j = 0;
                }
            }
            else {
                if(nums[i] > nums[i+1]) {
                    i++;
                    if(j==n-1) {
                        i = i-j;
                        j=0;
                        cnt++;
                    }
                    else j++;
                    
                }
                else {
                    i = i-j+1;
                    j = 0;
                }
            }
        }
        return cnt;
    }
};
