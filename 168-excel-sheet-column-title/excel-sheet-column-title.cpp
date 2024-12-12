class Solution {
public:
    string convertToTitle(int num) {
        
        string ans = "";

        while (num) {
            // subtract every time for 0-based indexing 26-base
            num--;
            int rem = num % 26;
            rem += 65;
            ans = char(rem) + ans;
            num /= 26;
        }

        return ans;
    }
};