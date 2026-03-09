class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        /* this function will compute the count of all subarray,

        Where the window satisfies:sum ≤ goal

        then all subarrays ending at r starting from l to r are valid.*/

        if(goal < 0) return 0;
        int l = 0;
        int sum = 0;
        int count = 0;

        for (int r = 0; r < nums.size(); r++) {

            sum += nums[r];

            while (sum > goal) {
                sum -= nums[l];
                l++;
            }

            count += (r - l + 1);
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        /*
        We compute:

        (subarrays with sum ≤ goal) - (subarrays with sum ≤ goal-1)

        This gives:
        subarrays with sum = goal

        */

        return atMost(nums,goal) - atMost(nums, goal-1);
    }
};
