class Solution {
private:
    void dfs(string beginWord, string word, vector<string> &seq, vector<vector<string>> &ans, unordered_map<string, int> &mpp) {

        if(word == beginWord) {
            vector<string> revSeq(seq.rbegin(), seq.rend());
            ans.push_back(revSeq);
            return;
        }

        int sz = word.size();
        int steps = mpp[word];

        for(int i = 0; i < sz; i++) {
            char original = word[i];

            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;

                if(mpp.find(word) != mpp.end() && mpp[word]+1 == steps) {
                    seq.push_back(word);
                    dfs(beginWord, word, seq, ans, mpp);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

     unordered_set<string> st(wordList.begin(), wordList.end());
        
     queue<string> q;
     unordered_map<string, int> mpp;
     q.push(beginWord);

     mpp[beginWord] = 1;

     int sz = beginWord.size();
     st.erase(beginWord);

     while(!q.empty()) {
        string word = q.front();
        int steps = mpp[word];
        q.pop();

        if(word == endWord) break;

        for(int i = 0; i < sz; i++) {
            char original = word[i];

            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;

                if(st.count(word)) {
                    q.push(word);
                    st.erase(word);

                    mpp[word] = steps+1;
                }
            }

            word[i] = original;
        }
     }

     vector<vector<string>> ans;

     if(mpp.find(endWord) != mpp.end()){
        vector<string> seq;
        seq.push_back(endWord);
        dfs(beginWord, endWord, seq, ans, mpp);
     }

     return ans;

     




    }
};