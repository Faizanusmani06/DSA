class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        int minVal = *min_element(bloomDay.begin(), bloomDay.end());
        int maxVal = *max_element(bloomDay.begin(), bloomDay.end());

        bool f = false;
        int low = minVal, high = maxVal;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int cnt = 0, bq = 0;
            for (int j = 0; j < n; j++) {

                if (bloomDay[j] <= mid)
                    cnt++;
                else
                    cnt = 0;

                if (cnt == k) {
                    bq++;
                    cnt = 0;
                }
            }

            if (bq >= m) {
                f = true;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        if (!f)
            return -1;
        return low;
    }
};