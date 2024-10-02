class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<string, char> mp1;
        map<char, string> mp2;

        int j = 0;
        int i = 0;
        string word = "";
        while (i < s.size()) {
            if (s[i] == ' ') {
                cout << word << " " << pattern[j] << endl;
                
                if(mp1.find(word)!= mp1.end() && mp1[word] != pattern[j]) return false;
                else if(mp1.find(word)== mp1.end() && mp2.find(pattern[j])!= mp2.end()) return false;
                else {
                    mp1[word] = pattern[j];
                    mp2[pattern[j]] = word;
                }
                word = "";
                j++;

            } else
                word += s[i];
            i++;
        }

        if(j != pattern.size() - 1) return false;
        if(pattern.size() == 1 && mp1.size() == 0) return true;
        if((mp1.find(word)!= mp1.end() && mp1[word] != pattern[j]) || (mp1.find(word)== mp1.end() && mp2.find(pattern[j]) != mp2.end())) return false;
       
        return true;
    }
};