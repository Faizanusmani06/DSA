class Solution {
    bool isPalindrome(int i, int j, string s) {
        while (j > i) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    void solve(int ind, vector<string>& ds, vector<vector<string>>& ans,
               string s) {

        if (ind == s.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = ind; i < s.size(); i++) {
            if (isPalindrome(ind, i, s)) {
                ds.push_back(s.substr(ind, i + 1 - ind));
                solve(i + 1, ds, ans, s);
                ds.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;

        solve(0, ds, ans, s);

        return ans;
    }
};