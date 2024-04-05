class Solution {
public:
    string makeGood(string s) {
        if(!s.size()) return "";
        stack<char> st;
        st.push(s[0]);
        for(int i = 1; i < s.size(); i++) {
            char ch1 = s[i];
            if(!st.size()) st.push(s[i]);
            else {
                if(abs(int(s[i]) - int(st.top())) == 32) st.pop();
                else st.push(s[i]);
            }
            
        }

        string ans = "";

        while(!st.empty()) {
            ans =  st.top() + ans;
            st.pop();
        }

        return ans;
    }
};