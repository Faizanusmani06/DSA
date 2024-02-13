// 2108. Find First Palindromic String in the Array

class Solution {
private:
    bool isPalindromic(string &s) {
        int i = 0;
        int j = s.size() - 1;

        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(string s : words) {
            if(isPalindromic(s)) return s;
        }
        return "";
    }
};
