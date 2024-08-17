class Solution {
public:
    bool isValid(string str) {
        stack<char> st;

        st.push('a');
        cout << st.top();
        for(char ch : str) {
            if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else if((ch == ')' && st.top() == '(') || (ch == '}' && st.top() == '{') || (ch == ']' && st.top() == '[')) st.pop();
            else return false;
            
        }
        if(st.size() == 1) return true;
        else return false;
    }
};