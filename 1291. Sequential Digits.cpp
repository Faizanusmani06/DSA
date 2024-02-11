class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str = "123456789";

        vector<int> ans;

        for(int i = 0; i < str.size(); i++) {
            for(int j = i+1; j <= str.size(); j++) {
                int value = stoi(str.substr(i, j-i));
                if(value >= low && value <= high) ans.push_back(value);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
