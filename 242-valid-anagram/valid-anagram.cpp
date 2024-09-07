class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mp;

        for(auto ch : s) {
            mp[ch]++;
        }

        for(auto ch: t) {
            mp[ch]--;
            if(mp[ch] == 0) mp.erase(ch);
        }

        if(mp.size() == 0) return true;
        else return false;
    }
};