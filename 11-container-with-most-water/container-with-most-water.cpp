class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i = 0, j = height.size() - 1;
        int ans = -1; int mul = 0;
        while(i < j) {
            mul = (j-i) * min(height[i], height[j]);

            ans = max(ans, mul);

            if(height[i] > height[j]) j--;
            else i++;
        }
        return ans;
    }
};