class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cntZeroes = 0;
        int cntOnes = 0;
        int m = students.size();
        int n = sandwiches.size();
        for(int i = 0; i < m; i++) {
            if(students[i] == 0) cntZeroes++;
            if(students[i] == 1) cntOnes++;
        }
        int j = 0;
        int i = 0;
        while(j < n) {
            cout << j << endl;
            if((sandwiches[j] == 0 && cntZeroes <= 0) || (sandwiches[j] == 1 && cntOnes <= 0)) break;
            if(sandwiches[j] == students[i]) {
                if(students[i]==0) cntZeroes--;
                if(students[i]==1) cntOnes--;
                j++;
                i = (i+1) % m;
            }else {
                while(sandwiches[j] != students[i]) i = (i+1) % m;
            }
        }
        return n-j;
    }
};