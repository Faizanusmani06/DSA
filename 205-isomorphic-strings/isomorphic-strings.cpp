class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();

        if(n1 != n2) 
            return false;

        unordered_map <char, char> my_map;
        set <char> my_set;


        for(int i = 0; i < n1; i++) {
            char c1 = s[i];
            char c2 = t[i];

            if(my_map.find(c1) != my_map.end()) {
                if(my_map[c1] != c2) 
                    return false;
            }

            else {
                if(my_set.find(c2) != my_set.end())
                    return false;

                my_map[c1] = c2;
                my_set.insert(c2);
            }
        }
        return true;
    }
};