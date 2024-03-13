class Solution {
private:
    int binarySearch(int l, int r, int n) {
        if(l <= r ) {
            int mid = l + (r-l)/2;
            
            int sum1 = mid*(mid+1)/2;
            int sum2 = n*(n+1)/2 - sum1 + mid;

            if(sum1 == sum2 ) return mid;
            else if(sum1 > sum2) return binarySearch(l, mid-1, n);
            else return binarySearch(mid+1, r, n);
        }
        return -1;
    }
public:
    int pivotInteger(int n) {
        return binarySearch(1, n, n);
    }
};