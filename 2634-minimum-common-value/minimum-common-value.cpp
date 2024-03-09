class Solution {
int binary_search(vector<int> &nums, int l, int r, int x) {
    while(l <= r) {
        int mid = l + (r-l)/2;

        if(nums[mid] == x) return mid;
        else if(nums[mid] > x) r = mid - 1;
        else l = mid + 1;
    }

    return -1;
}
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i = 0; i < n1; i++) {
            int x = nums1[i];

            int idx = binary_search(nums2, 0, n2-1, x);
            if(idx != -1) return nums2[idx];

        }

        return -1;
    }
};