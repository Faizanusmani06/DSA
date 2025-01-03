class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char, bool> mp;
        int cnt = 0;
        for (char ch : allowed) {
            mp[ch] = true;
        }

        for (string str : words) {
            bool flag = true;
            for (char ch : str) {
                if (!mp[ch]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                cnt++;
        }

        return cnt;
    }
};