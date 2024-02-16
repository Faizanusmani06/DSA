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

// class Solution {
// public:
//     int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
//         unordered_map<int, int> mp;
//         for(int i: arr) {
//             mp[i]++;
//         }
//         map<int, vector<int>> new_mp;
//         auto it = mp.begin();
//         while(it != mp.end()) {
//             new_mp[it->second].push_back(it->first);
//             it++;
//         }
//         int ans = 0;
//         auto it1 = new_mp.begin();
//         while(it1 != new_mp.end()) {
//             if(k) {
//                 int total = it1->first*(it1->second.size());
//                 if(k >= total) {
//                     k -= total;
//                 }else {
//                     ans += (it1->second.size() - k/it1->first);
//                     k = 0;
//                 }
//             }else {
//                 ans += (it1->second.size());
//             }
//             it1++;
//         }

//         return ans;
//     }
// };
