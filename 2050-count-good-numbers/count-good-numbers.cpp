class Solution {
    int mod = 1000000007;
    long long power(long long x, long long n) {
        if(n==0) return 1;

        long long ans = power(x, n/2);

        ans *= ans;
        ans %= mod;

        if(n % 2 == 1) {
            ans *= x;
            ans %= mod;
        }

        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = n - odd;
        
        return power(5, even) * power(4, odd) % mod;
    }
};