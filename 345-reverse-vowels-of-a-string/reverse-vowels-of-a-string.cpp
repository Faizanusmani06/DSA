class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;

        string vowel = "aeiouAEIOU";

        while(i < j) {
            while(vowel.find(s[i]) == string::npos && i < j) i++;
            while(vowel.find(s[j]) == string::npos && i < j) j--;

            swap(s[i++], s[j--]);
        }
        return s;
    }
};