class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        set<pair<int, int>> st;
        for(int i = 0; i < m; i++) {
            
            int low = 0, high = n-1;

            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(mat[i][mid] == 0) high = mid - 1;
                else low = mid + 1;
            }

            st.insert({high, i});

        }
        vector<int> ans;
        for(auto it : st) {
            if(!k) break;
            ans.push_back(it.second);
            k--;
        }
        return ans;
    }
};