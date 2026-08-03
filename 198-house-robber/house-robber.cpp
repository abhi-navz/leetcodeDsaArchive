class Solution {
public:
    // int solve(int idx, vector<int>&nums, vector<int>&dp){
    //     int n = nums.size();
    //     if(idx >= n) return 0;
    //     if(dp[idx] != -1) return dp[idx];

    //     // robbing 
    //     int r1 = nums[idx]+solve(idx+2, nums,dp);
    //     // not robbing
    //     int r2 = solve(idx+1,nums,dp);

    //     return dp[idx] =  max(r1,r2);

    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        for(int i= 2; i<n; i++){
            dp[i] = max(
                dp[i-1], // not robbing i
                dp[i-2]+nums[i] // robbing i;
            );
        }

        return dp[n-1];
    }
};