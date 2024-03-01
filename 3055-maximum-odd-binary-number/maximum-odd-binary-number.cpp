class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans = "";
        int n = s.size();
        for(char ch : s) {
            if(ch == '1') {
                ans = ch + ans; 
            }else ans += ch;
        }

        return ans.substr(1, n)+'1';
    }
};