class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int l = 0, r = 0;
        int maxLen = 0;

        int count = 0;
        int n = nums.size();

        while (r < n) {

            if (nums[r] == 0)
                count++;

            if (count > k) { // while can be replaced with if, because we are
                             // just sliding the window, not increasing the size
                             // from previous valid window.

                if (nums[l] == 0)
                    count--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};
