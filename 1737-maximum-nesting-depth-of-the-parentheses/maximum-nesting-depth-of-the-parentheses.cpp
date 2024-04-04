class Solution {
public:
    int maxDepth(string s) {
        int max_depth = 0;
        int count = 0;

        for(char ch: s) {
            if(ch == '(') count++;
            if(ch == ')') count--;

            max_depth = max(max_depth, count);
        }
        return max_depth;
    }
};