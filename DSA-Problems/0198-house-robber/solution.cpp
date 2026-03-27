class Solution {
public:
    
    int rob(vector<int>& nums) {
       int  n = nums.size();
       if(n == 1) return nums[0];
        // vector<int>dp(n+1,-1);
        int prev2 = nums[0]; // replacing dp[0]
        int prev1 = max(nums[0], nums[1]); //replacing dp[1]

        for(int idx = 2; idx<n; idx++){
            // not robbing current house
            int l1 = prev1;
            // robbing current house
            int l2 = nums[idx] + prev2;
            int curr = max(l1,l2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
