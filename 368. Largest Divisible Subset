// 368. Largest Divisible Subset
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> grpSize(n, 1), prevElement(n, -1);

        int maxInd = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && (grpSize[i] < grpSize[j] + 1)) {
                    grpSize[i] = grpSize[j] + 1;
                    prevElement[i] = j;
                }
            }
            if(grpSize[i] > grpSize[maxInd]) {
                maxInd = i;
            }
        }

        vector<int> ans;

        for(int i = maxInd; i != -1; i = prevElement[i]) {
            ans.push_back(nums[i]);
        }

        return ans;
    }
};
