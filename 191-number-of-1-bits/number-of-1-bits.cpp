class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n) {
            int x = n&1;
            if(x) ans++;
            n >>= 1;
        }

        return ans;
    }
};