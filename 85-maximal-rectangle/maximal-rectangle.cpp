class Solution {
    int largestArea(vector<int> &arr) {
        int area = 0;
        int n = arr.size();
        stack<int> st;
        
        for(int i = 0; i <= n; i++) {
            
            while(!st.empty() && (i == n || arr[st.top()] >= arr[i])) {
                int height = arr[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;

                area = max(area, width * height);
            }
            st.push(i);
        }

        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix[0].size();
        vector<int> arr(m, 0);
        int n = matrix.size();
        int area = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') arr[j]++;
                else arr[j] = 0;
            }
            for(auto i: arr) cout << i << endl;
            area = max(area, largestArea(arr));
        }

        return area;
    }
};