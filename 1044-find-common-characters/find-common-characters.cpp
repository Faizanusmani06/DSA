class Solution {
private:
    vector<int> count(const string& str) {
        vector<int> freq(26, 0);
        for(char c : str) {
            freq[c-'a']++;
        }
        return freq;
    }

    vector<int> intersection(const vector<int>& freq1, const vector<int>& freq2) {
        vector<int> freq3(26, 0);
        for(int i = 0; i < 26; i++) {
            freq3[i] = min(freq1[i], freq2[i]);
        }

        return freq3;
    }
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> last = count(words[0]);

        for(int i = 1; i < words.size(); i++) {

            last = intersection(last, count(words[i]));
        }

        vector<string> ans;

        for(int i = 0; i < 26; i++) {
            while(last[i] > 0) {
                ans.push_back(string(1, 'a' + i));
                last[i]--;
            }
        }

        return ans;
    }
};