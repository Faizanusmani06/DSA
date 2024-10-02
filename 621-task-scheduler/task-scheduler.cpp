class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        int size = tasks.size();
        for(char ch: tasks) freq[ch - 'A']++;

        sort(begin(freq), end(freq));

        int chunks = freq[25] - 1;

        int idle = chunks * n;

        for(int i = 24; i >= 0; i--) {
            idle -= min(chunks, freq[i]);
        }

        return idle < 0 ? size : size + idle;
    }
};