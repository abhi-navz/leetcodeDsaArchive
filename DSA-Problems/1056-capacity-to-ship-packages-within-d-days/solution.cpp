class Solution {
public:
    int findDays(vector<int>& weights, int mid) {

        int currLoad = 0;
        int days = 1; // minimum 1 day

        for (int w : weights) {
            if (w > mid) {
                return INT_MAX; // impossible weight for current capacity so
                                // returning big no of days
            }
            if (currLoad + w > mid) {
                days++; // new days starts
                currLoad = w;

            } else {
                currLoad += w;
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1, high = 0;

        for (int x : weights) {
            low = max(low, x);
            high += x ;
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = findDays(weights, mid);
            if (count <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
