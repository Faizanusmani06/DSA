class Solution {
public:
    

    bool isPalindrome(string s) {
       string str = "";
       for(char ch : s) {
           int ascii = int(ch);
           if((ascii >= 97 && ascii <= 122) || (ascii >= 48 && ascii <= 57)) {
               str.push_back(ch);
           }else if((ascii >= 65 && ascii <= 90)) {
               str.push_back(ch+32);
           }
       }

       int i = 0, j = str.size() - 1;
       while(i < j) {
           if(str[i] != str[j]) return false;
           else {
               i++;
               j--;
           }
       }

       return true;
    }
};