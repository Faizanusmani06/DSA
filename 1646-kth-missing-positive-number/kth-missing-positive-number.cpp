class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        if((k - arr[0] + 1) <= 0) return k;
        else k -= arr[0] - 1; 

        for(int i = 1; i < n; i++) {
            int miss = arr[i] - arr[i-1] - 1;
            if(miss >= k) return arr[i-1] + k;
            else k -= miss;
        }

        return arr[n-1] + k;
       
    }
};