class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int index1 = -1, index2 =-1;
        vector<int>x(2,-1);
        int i = 0, j = numbers.size()-1;
        while(i<=j)
        {
            int sum = numbers[i]+numbers[j];
            if(sum==target)
            {
                x[0]=i+1;
                x[1]=j+1;
                return x;
            }
            if(sum < target)i++;
            else j--;
        }
        return x;
        
    }
};