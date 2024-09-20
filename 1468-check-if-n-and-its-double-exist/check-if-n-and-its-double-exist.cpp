class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int, int> mp;

        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i] * 2] = i;
        }

        for(int i = 0; i < arr.size(); i++) {
            if(mp.find(arr[i]) != mp.end() && mp[arr[i]] != i) {
                return true;
            }
        }

        return false;
        

    }
};