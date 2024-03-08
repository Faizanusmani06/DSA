class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);

        for(int i : nums) {
            freq[i]++;
        }

        sort(freq.rbegin(), freq.rend());
        int ans = freq[0];
        int i = 0;
        int cnt = 1;
        while(freq[i] == freq[i+1] && i < 100) {
            i++;
            cnt++;
        }

        ans *= cnt;
        return ans;
    }
};