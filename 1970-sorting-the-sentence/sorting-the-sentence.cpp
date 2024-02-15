class Solution {
public:
    string sortSentence(string s) {
        map<int, string> mp;
        string str = "";
        for(char i: s) {
            if(i >= 48 && i <= 57) {
                mp[int(i) - 48] = str;
                str = "";
            }
            else{
                if(i != ' ') str += i;
            }
                
        }

        str = "";
        auto it = mp.begin();
        while(it != mp.end()) {
            str += it->second;
            it++;
            if(it != mp.end()) str+=" ";
        }

        return str;
    }
};