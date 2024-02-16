class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (auto i : arr) {
            mp[i]++;
        }
        int n = mp.size();
        vector<int> temp(n);
        int j = 0;
        for (auto i : mp) {
            temp[j] = i.second;
            j++;
        }
        sort(temp.begin(), temp.end());

        j = 0;
        int ans = temp.size();
        while (k > 0) {
            while (temp[j] > 0 && k > 0) {
                temp[j]--;
                k--;
            }
            if (temp[j] == 0) {
                j++;
                ans--;
            }
        }
        return ans;
    }
};