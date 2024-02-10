// 647. Palindromic Substrings

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        // int n = s.length();

        // vector<vector<bool>> pal(n, vector<bool>(n, false));

        // int ans = 0;

        // for(int len = 1; len <= n; len++) {
        //     for(int i = 0; i < n - len + 1; i++) {
        //         if(s[i] == s[i + len - 1] && ((len <= 2) || (pal[i+1][i+len-2]))) {
        //             pal[i][i + len - 1] = true;
        //             ans++;
        //         }
        //     }
        // }

        // return ans;

        int n = s.length(), ans = 0;
        for (int i = 0; i < n; ++i) {
            int even = palindromeCount(s, i, i + 1);
            int odd = palindromeCount(s, i, i);
            ans += even + odd;
        }
        return ans;
        }

        int palindromeCount(const string& s, int left, int right) {
            int count = 0;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                --left;
                ++right;
                ++count;
            }
            return count;
        }
    };
    
