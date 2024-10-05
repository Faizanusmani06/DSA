class Solution {
    string reverse(string str, int i, int j) {
        if(j >= str.size()) j = str.size() - 1;
        while(i < j) swap(str[i++], str[j--]);
        return str;
    }
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int i = 0, j = k-1;

        int cnt = (n/(2*k)) + 1;

        while(cnt--) {
            s = reverse(s, i, j);
            i += 2*k;
            j = i + k - 1;
            if(j >= n) j = n-1;
        }
        return s;
    }
};