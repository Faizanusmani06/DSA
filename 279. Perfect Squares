// 279. Perfect Squares


class Solution {
public:
    int numSquares(int n) {
        int sqrtValue = sqrt(n);

        if(sqrtValue * sqrtValue == n) return 1;
        int x = n;
        while(x % 4 == 0) x /= 4;

        if(x%8==7) return 4;
        

        for(int i = 1; i*i <= n; i++) {
            int squareA = i*i;

            int squareB = sqrt(n - squareA);

            if(squareB*squareB == (n-squareA)) return 2;
        }

        return 3;
    }
};




class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j){
            dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};


