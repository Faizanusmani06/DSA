class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int value = nums[0];
        int cnt = 0;

        for(int a: nums) {
            if(cnt == 0) {
                value = a;
            }

            cnt += (value == a) ? 1 : -1;
        }
        return value;
    }
};