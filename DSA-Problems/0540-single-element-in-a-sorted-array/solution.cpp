class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        /*
            Pattern: Before the single element the pair starts at even index and
           end at odd index but after single element the pair start at odd
           index.
        */

        int st = 0, end = n - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            if (mid % 2 != 0) {
                if (nums[mid - 1] == nums[mid]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }

            } else {
                // mid is even
                if (nums[mid] == nums[mid + 1]) {
                    st = mid + 2;
                } else {
                    end = mid; // mid could be answer as the patter is break
                               // after mid;
                }
            }
        }

        return nums[st];
    }
};
