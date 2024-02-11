// Minimum Window Substring leetcode

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()) return "";

        unordered_map<char, int> dict;
        for(char c : t) {
            dict[c]++;
        }

        int dict_uniqueChar = dict.size();

        int left = 0, right = 0;
        int wind_uniqueChar = 0;

        unordered_map<char, int> window;
        int ans[3] = {-1, 0, 0};

        while(right < s.size()) {
            char ch = s[right];
            window[ch]++;

            if(dict.contains(ch) && window[ch] == dict[ch]) wind_uniqueChar++;

            while(left <= right && wind_uniqueChar == dict_uniqueChar) {
                char ch = s[left];

                if(ans[0] == -1 || (right-left+1 < ans[0])) {
                    ans[0] = right - left + 1;
                    ans[1] = left;
                    ans[2] = right;
                }

                window[ch]--;

                if(dict.contains(ch) && window[ch] < dict[ch]) {
                    wind_uniqueChar--;
                }
                left++;
            }
            right++;
        }
        return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
    }
};



