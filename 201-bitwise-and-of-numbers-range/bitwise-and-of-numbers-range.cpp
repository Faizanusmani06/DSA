class Solution {
private:
    int find_msb(int value) {
        int ans = 0;
        while(value) {
            value >>= 1;
            ans++;
        }
        return ans-1;
    }
public:
    int rangeBitwiseAnd(int left, int right) {
        
        int ans = 0;
        while(left && right) {
            int msb_left = find_msb(left);
            int msb_right = find_msb(right);

            if(msb_left != msb_right) break;

            int msb_value = 1 << msb_left;

            ans += msb_value;
            left -= msb_value;
            right -= msb_value;
        }

        return ans;
    }
};