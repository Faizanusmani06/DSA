class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int n1 = aliceSizes.size();
        int n2 = bobSizes.size();

        sort(bobSizes.begin(), bobSizes.end());

        long long sum1 = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        long long sum2 = accumulate(bobSizes.begin(), bobSizes.end(), 0);

        for(int i : aliceSizes) {
            sum1 -= i;

            int low = 0, high = n2-1;

            while(low <= high) {
                int mid = low + (high - low) / 2;

                sum2 = (sum2 - bobSizes[mid] + i);

                sum1 += bobSizes[mid];

                if(sum1 == sum2) return {i, bobSizes[mid]};
                else if(sum1 > sum2) high = mid - 1;
                else low = mid + 1;

                sum2 = (sum2 + bobSizes[mid] - i);
                sum1 -= bobSizes[mid];
            }
            sum1 += i;
        }
        return {};
    }
};