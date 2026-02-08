class Solution {
public:
    int value(vector<int>& nums, int mid, int threshold) {
        long long sum = 0;
        for (int x : nums) {
            sum += (x + mid - 1LL) / mid;
            if(sum>threshold)
                return sum;
           
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {

        int low = 1, high = 1;
        // finding the max element of the array
        for (int x : nums) {
            high = max(high, x);
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = value(nums, mid,threshold);
            if (val <= threshold) {
                // go left and find smaller
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
