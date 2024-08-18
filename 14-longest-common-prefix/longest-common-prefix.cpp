class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        sort(strs.begin(), strs.end());
        int n = strs.size()-1;
        int i = 0, j = 0;

        while(i < strs[0].size() && j < strs[n].size() && strs[0][i++] == strs[n][j++]) {
            ans += strs[0][i-1];
        }

        return ans;
    }
};