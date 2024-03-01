class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0;
        int zeroes = 0;
        string ans = "";
        for(char ch : s) {
            if(ch == '1') ones++;
            else zeroes++;
        }

        while(ones > 1) {
            ans += '1';
            ones--;
        }
        while(zeroes > 0) {
            ans += '0';
            zeroes--;
        }

        return ans+'1';
    }
};