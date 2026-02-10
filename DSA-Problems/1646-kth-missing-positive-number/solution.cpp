class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // optimal
        //  no of missing ele at i = arr[i]-(i+1);

        int low = 0, high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // answer:
        /* high will end up before low after loop : high+1 = low
        and the answer exist between arr[high] and arr[low];
        we will find number of elements missing at high which will be less than the
        Kth missing element we need. at high: missingAtHigh = arr[high] - (high+1);
        more we need : more = k-missingAtHigh
         ans = arr[high]+more
         = arr[high] + k - missingAtHigh;
         = arr[high]+k - (arr[high] - high - 1)
         = arr[high]+k - arr[high]+high + 1
         = high+1+k
         = low+k;

       */

       // we can't directly return arr[high]+more : because in case like [1 2 3 4 5] and k = 2
       // high will go negative and returning it'll give overboudn error.

        return low + k;
    }
};
