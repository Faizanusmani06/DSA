class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;

        for(char i : s) {
            mp[i]++;
        }

        int i = 0;
        string ans = "";
        int n = order.size();

        while(i < n) {
            char ch = order[i];
            while(mp[ch]) {
                ans += ch;
                mp[ch]--;
            }
            i++;
        }
        for(auto i : mp) {
            while(i.second) {
                ans += i.first;
                i.second--;
            }
        }
        return ans;
    }
};