class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int xorSum = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) xorSum ^= nums[i];

        for(int i = 0; i < n-2; i++) xorSum ^= i;

        int rightMostSetBit = xorSum & ~(xorSum - 1);


        int first = 0;
        int second = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] & rightMostSetBit) {
                first ^= nums[i];
            }else second ^= nums[i];
        }

        for(int i = 0; i < n-2; i++) {
            if(i & rightMostSetBit) {
                first ^= i;
            }else second ^= i;
        }

        return {first, second};

    }
};