class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> unique; 
        int left = 0;            
        int currSum = 0;      
        int maxSum = 0;        
        
       
        for (int right = 0; right < nums.size(); right++) {
            while (unique.count(nums[right])) {
                unique.erase(nums[left]);      
                currSum -= nums[left];    
                left++;                      
            }
            
           
            unique.insert(nums[right]);        
            currSum += nums[right];       
            
          
            maxSum = max(maxSum, currSum);
        }
        
        return maxSum;
    }
};