class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int i = 0, j = n-1;
        
        if(s[i] != s[j]) return n;
        while(i <= j) {

            if(i==j) return 1;
            char c = s[i];

            while(s[i] == c && i < n) i++;
            while(s[j] == c && j > 0) j--;

            if(s[i] != s[j] && i < n && j > 0) return j-i+1;
        }

        return 0;
    }
};