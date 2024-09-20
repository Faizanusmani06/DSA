class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int cnt = 0;
        int n1 = arr1.size();
        int n2 = arr2.size();
        for(int i = 0; i < n1; i++) {
            int ele = arr1[i];
            bool eq = false;
            int low = 0, high =  n2 - 1;

            while(low <= high) {
                int mid = low + (high - low) / 2;

                if(arr2[mid] == ele) {
                    eq = true;
                    break;
                }else if (arr2[mid] > ele) high = mid - 1;
                else low = mid + 1;
            }
            if(eq) continue;
            cout << low << " " << high << endl;
            if(high < 0 && arr2[low] - ele > d) cnt++;
            else if(low >= n2 && ele - arr2[high]> d) cnt++;
            else if(low < n2 && high >= 0 && ( (arr2[low] - ele) > d ) && ((ele - arr2[high]) > d)) cnt++; 
            
        }

        return cnt;
    }
};