class Solution {
    void solve(string str, vector<string> &ans, int open, int close) {
        if(!open && !close) {
            ans.push_back(str);
            return;
        }
       
        if(open) {
            solve(str+"(", ans, open-1, close);
        }
        if(close && open < close) {
            solve(str+")", ans, open, close-1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string str = "";
        vector<string> ans;
        solve(str, ans, n, n);

        return ans;
    }
};