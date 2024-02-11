// using dp

class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        int prev = 1;
        int pprev = 0;

        for(int i = 2; i <= n; i++) {
            int total = prev + pprev;
            pprev = prev;
            prev = total;
        }
        return prev;
    }
};


class Solution {
// public:
//     int fib(int n) {
//         if(n <= 1) return n;
//         vector<int> fib(n+1, -1);
//         fib[0] = 0;
//         fib[1] = 1;

//         for(int i = 2; i <= n; i++) {
//             fib[i] = fib[i-1] + fib[i-2];
//         }
//         return fib[n];
//     }
// };
