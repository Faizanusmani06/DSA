class Solution {
    void solve(int i, vector<int>&arr, int target, vector<vector<int>> &ans, vector<int> &temp) {
        if(i == arr.size()) {
            if(target == 0) ans.push_back(temp);
            return;
        }

        if(arr[i] <= target) {
            temp.push_back(arr[i]);
            solve(i, arr, target-arr[i], ans, temp);
            temp.pop_back();
        }
        solve(i+1, arr, target, ans, temp);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, candidates, target, ans, temp);

        return ans;
    }
};