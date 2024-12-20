class Solution {
public:
    vector<int> getRow(int rowIndex) {
            if(rowIndex == 0) return {1};
            if(rowIndex == 1) return {1, 1};

            vector<int> ans = {1, 1};

            while(rowIndex >= 2) {
                for(int i = ans.size()-1; i > 0; i--) {
                    ans[i] = ans[i] + ans[i-1];
                }
                ans.push_back(1);
                rowIndex--;
            }

            return ans;
    }
};