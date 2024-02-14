// z_algo O(n+m)

class Solution {
private:
    void z_func(string str, vector<int> &z) {
            int n = str.size();
            int L, K, R;
            L=R=0;
            
            for(int i = 1; i < n; i++) {
                if(i > R) {
                    L=R=i;
                    while(R<n && str[R-L] == str[R]) {
                        R++;
                    }
                    z[i] = R-L;
                    R--;
                }else {
                    K = i-L;
                    
                    if(z[K] < (R-i+1)) {
                        z[i] = z[K];
                    }else {
                        L = i;
                        
                        while(R < n && str[R-L] == str[R]) {
                            R++;
                        }
                        z[i] = R-L;
                        R--;
                    }
                }
            }
        }
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        string str = "";
        string pat = "";
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] == nums[i+1]) str += "b";
            else if(nums[i] < nums[i+1]) str += "a";
            else str += "c";
        }
        
        for(int i = 0; i < pattern.size(); i++) {
            if(pattern[i] == 1) pat += "a";
            else if(pattern[i] == 0) pat += "b";
            else pat += "c";
        }
        string new_string = pat + "#" + str;
        int n = new_string.length();
        vector<int> z(n, 0);
        z_func(new_string, z);
            
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(z[i] == pat.size()) {
                cnt++;
            }
                
        }
        return cnt;
     
    }
};
