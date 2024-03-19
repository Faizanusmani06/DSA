class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};

        for(char ch : tasks) {
            freq[ch-'A']++;
        }

        sort(begin(freq), end(freq));

        int batches = freq[25]-1;
        int idle = batches * n;

        for(int i = 24; i >= 0; i--) {
            idle -= min(freq[i], batches);
        }

        return idle<0 ? tasks.size() : tasks.size()+idle;
    }
};