class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        int n = s.size();
        int flag = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s[i]!=' ') flag = 1;
            if(flag && s[i]!=' ')cnt++;
            if(flag && s[i]==' ') break;
        }
        return cnt;
    }
};