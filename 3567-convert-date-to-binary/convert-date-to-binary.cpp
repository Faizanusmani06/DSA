class Solution {
public:
    string convertDateToBinary(string date) {
        vector<int> d;
        string str = "";
        for (char ch : date) {
            if (ch == '-') {
                d.push_back(stoi(str));
                str = "";
                continue;
            }
            str += ch;
        }
        d.push_back(stoi(str));

        for (int i : d) {
            cout << i << endl;
        }

        string ans = "";

        for (int i : d) {
            string temp = "";
            while (i != 1 && i != 0) {
                int rem = i % 2;
                temp = to_string(rem) + temp;
                i /= 2;
            }
            if (i == 1)
                temp = "1" + temp;

            if (ans == "")
                ans += temp;
            else
                ans = ans + "-" + temp;
            temp = "";
        }
        return ans;
    }
};