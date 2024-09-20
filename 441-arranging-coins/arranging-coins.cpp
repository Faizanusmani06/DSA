class Solution {
public:
    int arrangeCoins(int n) {
        long long low = 1, high = n;

        while(low <= high) {
            long long mid = low + (high - low) / 2;

            long long ans = mid*(mid+1)/2;
            if(ans > INT_MAX) {
                high = mid - 1;
                continue;
            }

            if(ans == n) return mid;
            else if(ans > n) high = mid - 1;
            else low = mid + 1;
        
        }

        return high;
    }
};