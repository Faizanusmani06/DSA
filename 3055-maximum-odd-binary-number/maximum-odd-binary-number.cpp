class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.rbegin(), s.rend());
        return s.substr(1, s.size())+'1';
    }
};