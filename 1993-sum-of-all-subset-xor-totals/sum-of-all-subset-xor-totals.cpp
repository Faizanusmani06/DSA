class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return XORSum(nums, 0, 0);
    }

private:
    int XORSum(vector<int> &nums, int index, int currentXOR) {

        if(index == nums.size()) return currentXOR;

        int withEle = XORSum(nums, index+1, currentXOR^nums[index]);

        int withoutEle = XORSum(nums, index+1, currentXOR);

        return withEle + withoutEle;
    }
};