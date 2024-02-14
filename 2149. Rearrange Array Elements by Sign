// 2149. Rearrange Array Elements by Sign

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(N, 0);
        int p = 0, n = 0;

        for(int i = 0; i < N; i++) {
            int ele = nums[i];
            if(ele < 0) {
                ans[2*n + 1] = ele;
                n++;
            }else {
                ans[2*p] = ele;
                p++;
            }
        }

        return ans;
    }
};
