class Solution {
    double solve(double n) {
        cout << n << endl;
        if(int(n) != n) return false;
        if(n <= 3) {
            if(n == 3 ) return 1;
            else return 0;
        }
        return solve(n/3);
    }
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        if(n==1) return true;
        if(solve(double(n))) return true;
        return false;
    }
};