class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> para;

        string ans = "";

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                para.push(s[i]);
                ans += s[i];
            }else if(s[i] == ')') {
                if(!para.empty()) {
                    ans += s[i];
                    para.pop();
                }
            } else {
                ans += s[i];
            }
        }
        if(!para.empty()) {
            string res = "";
            int j;
            for(j = ans.size()-1; j >= 0; j--) {
                if(ans[j] == '(') {
                    para.pop();
                }
                else res = ans[j] + res;
                if(para.empty()) break;
            }

            res = ans.substr(0, j) + res;
            return res;
        }
        return ans;
    }
};