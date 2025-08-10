class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int i = 0, j;

        while (i < n && nums[i] != val)
            i++;

        j = i + 1;

        while (i < n && j < n) {
            if (nums[j] == val)
                j++;
            else {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j++;
                while (i < n && nums[i] != val)
                    i++;
                while (j < n && nums[j] == val)
                    j++;
            }
        }

        return i;
    }
};