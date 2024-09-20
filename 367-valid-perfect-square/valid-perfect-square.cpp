class Solution {
public:
    bool isPerfectSquare(int num) {
       
        int low = 1, high = num;
        int s = sqrt(INT_MAX);
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(mid > s) {
                high = mid - 1;
                continue;
            }
            int val = mid * mid;

            if(val == num) return true;
            else if(val > num) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};