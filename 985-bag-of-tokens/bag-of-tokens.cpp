class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int total =  0;
        int maxi = 0;
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());

        int i = 0, j = n-1;
        if(n == 0 || power < tokens[0] ) return 0;

       while(i <= j) {
           if(power >= tokens[i]) {
               power -= tokens[i++];
               total++;
               maxi = max(maxi, total);
           }else {
               power += tokens[j--];
               total--;
           }
       }

        return maxi;
    }
};