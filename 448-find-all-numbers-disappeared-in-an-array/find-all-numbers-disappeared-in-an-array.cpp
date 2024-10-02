class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int cnt = 1;
        for(int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " " << cnt << endl;
            if(i > 0 && nums[i] == nums[i-1]) continue; 
           
            while(cnt < nums[i]) {
                ans.push_back(cnt);
                cnt++;
            }
            cnt++;
        }

        while(cnt <= nums.size()) {
            ans.push_back(cnt++);
        }
        return ans;
    }
};