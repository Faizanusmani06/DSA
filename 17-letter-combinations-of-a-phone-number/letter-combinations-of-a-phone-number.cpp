class Solution {
    void solve(int ind, string digits, string str, vector<string> &ans, vector<string> arr) {
        cout << str << endl;
        if(ind == digits.size()) {
            ans.push_back(str);
            return;
        }
        string newStr = arr[int(digits[ind])-50];
        cout << newStr << endl;
        for(char ch: newStr) {
            str += ch;
            solve(ind+1, digits, str , ans, arr);

            str = str.substr(0, str.size()-1);
            
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> arr = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string str = "";
        vector<string> ans;
        solve(0, digits, str, ans, arr);
        return ans;

    }
};