class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int ele1 = INT_MIN, ele2 = INT_MIN;

        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(cnt1 == 0 && ele2 != nums[i]) {
                cnt1 = 1;
                ele1 = nums[i];
            }else if(cnt2 == 0 && ele1 != nums[i]) {
                cnt2 = 1;
                ele2 = nums[i];
            }else if(ele1 == nums[i]) cnt1++;
            else if(ele2 == nums[i]) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        int count1 = 0, count2 = 0;
        for(int i = 0; i < n; i++) {
            if(ele1 == nums[i]) count1++;
            if(ele2 == nums[i]) count2++;
        }

        bool flag1 = count1 > n/3;
        bool flag2 = count2 > n/3;

        if(flag1 && flag2) return {ele1, ele2};
        else if(flag1) return {ele1};
        else if(flag2) return {ele2};
        else return {};
    }
};