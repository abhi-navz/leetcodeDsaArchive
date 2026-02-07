class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();
        if (n == 1)
            return 0;

        int st = 0, end = n - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            // check direction of slope and movie in its direction of upper
            // slope

            if (nums[mid] <
                nums[mid + 1]) { // slope increaing in right->go right
                st = mid + 1;
            } else { // slope decreasing in right -> go left
                end = mid;
            }
        }

        return st;
    }
};
