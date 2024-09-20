class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1) {
            if(nums[0] == target) return {0};
            else return {};
        }
        sort(nums.begin(), nums.end());
        

        int low = 0, high = n - 1;

        int lInd = -1, hInd = -1;
        bool eq = false;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) eq = true;
            if (nums[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        if (low < n && eq)
            lInd = low;

        low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] <= target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        if (high >= 0 && eq)
            hInd = high;
        if (lInd == -1 && hInd == -1)
            return {};
        else if (lInd == -1 && hInd != -1)
            return {hInd};
        else if (lInd != -1 && hInd == -1)
            return {lInd};
        else {
            vector<int> ans;
            for(int i = lInd; i <= hInd; i++) ans.push_back(i);
            return ans;
        }
    }
};