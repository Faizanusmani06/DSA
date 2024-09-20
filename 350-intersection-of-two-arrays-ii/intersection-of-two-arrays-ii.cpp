class Solution {
    bool bSearch(vector<int> &arr, int x) {
        int low = 0, high = arr.size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(arr[mid] == x) return true;
            else if(arr[mid] > x) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        map<int, int> mp;

        for(int i : nums1) {
            mp[i]++;
        }

        for(int i : nums2) {
            if(mp.find(i) != mp.end()) {
                ans.push_back(i);
                mp[i]--;
                if(mp[i] == 0) mp.erase(i);
            }
            
        }

        return ans;
    }
};